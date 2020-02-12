#include "Mob.h"
#include "IdleState.h"
#include "SeekState.h"

#include <ResourceLoader.hpp>
#include <PackedScene.hpp>
#include <RandomNumberGenerator.hpp>

using namespace godot;

void Mob::_register_methods()
{
    register_property<Mob, float>("Speed", &Mob::set_Speed, &Mob::get_Speed, 50.0);
    register_method("_ready", &Mob::_ready);
    register_method("_process", &Mob::_process);
    register_method("_on_Sight_area_entered", &Mob::_on_Sight_area_entered);
}

void Mob::_init()
{
    // Initialize variables 
    skins = { "Red", "Green", "Blue" };
    Speed = 50;
}

void Mob::_ready()
{
    // Called when node enters scene tree
    RandomNumberGenerator* rng = RandomNumberGenerator::_new();
    // Get scene properties
    screen_size = get_viewport_rect().size;
    // Load random skin
    const char* skinIdx = skins[rng->randi() % 3].c_str();
    char path[50];
    sprintf(path, "res://scenes/skins/%s.tscn", skinIdx);
    ResourceLoader* ReLo = ResourceLoader::get_singleton();
    Ref<PackedScene> skinNode = ReLo->load(path);
    Node* skin = skinNode->instance();
    add_child(skin);
    // States
    _state = new IdleState(skin);
    updateFn = &State::HandleUpdate;
    signalFn = &State::collisionSignal;
}

void Mob::_process(float delta)
{
    Vector2 currPos = get_position();
    Vector2 dir = (_state->*updateFn)(delta);
    Vector2 newPos = currPos + (dir * Speed * delta);
    if (newPos.x - 10 <= 0)
        _state->reflect(Vector2(1,0));
    if (newPos.y - 10 <= 0)
        _state->reflect(Vector2(0,1));
    if (newPos.x + 10 >= screen_size.x)
        _state->reflect(Vector2(-1,0));
    if (newPos.y + 10 >= screen_size.y)
        _state->reflect(Vector2(0,-1));
    set_position(newPos);
    // flip sprite
    Node* spriteN = get_child(1)->get_child(0);
	Sprite* sprite = Node::cast_to<Sprite>(spriteN);
    if (dir.x != 0)
        sprite->set_flip_h( dir.x > 0 );
}

void Mob::_on_Sight_area_entered(Variant area)
{
    Node2D* node = Object::cast_to<Node2D>(area.operator Object*());
    StateList state = (_state->*signalFn)(node);
    if (state != _state->get_state())
    {
        _state = stateInit(state);
        _state->set_target(node->get_global_position());
    }
}

void Mob::set_Speed(float value)
{
    Speed = value;
}

float Mob::get_Speed()
{
    return Speed;
}

State* Mob::stateInit(StateList state)
{
    Node* skin = get_child(1);
    State* newState;
    switch (state)
    {
    case StateList::IdleState:
        newState = new IdleState(skin);
        break;

    case StateList::SeekState:
        newState = new SeekState(skin);
        break;
    }
    return newState;
}