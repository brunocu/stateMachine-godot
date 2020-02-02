#include "Mob.h"
#include "IdleState.h"

#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

using namespace godot;

void Mob::_register_methods()
{
    register_property<Mob, float>("Speed", &Mob::set_Speed, &Mob::get_Speed, 10.0);
    register_method("_ready", &Mob::_ready);
    register_method("_process", &Mob::_process);
};

void Mob::_init()
{
    // Initialize variables 
    skins = { "Red", "Green", "Blue" };
    Speed = 10;
};

void Mob::_ready()
{
    // Called when node enters scene tree
    // Get scene properties
    screen_size = get_viewport_rect().size;
    // Load random skin
    const char* skinIdx = skins[rand() % 3].c_str();
    char path[30];
    snprintf(path, 30, "res://scenes/skins/%s.tscn", skinIdx);
    ResourceLoader* ReLo = ResourceLoader::get_singleton();
    Ref<PackedScene> skinNode = ReLo->load(path);
    Node* skin = skinNode->instance();
    add_child(skin);
    // States
    _state = new IdleState(skin);
    updateFn = &State::HandleUpdate;
};

void Mob::_process(float delta)
{
    Vector2 currPos = get_position();
    Vector2 deltaPos = (_state->*updateFn)(delta);
    Vector2 newPos = currPos + (deltaPos * Speed * delta);
    newPos = clipPos(newPos);
    set_position(newPos);
};

void Mob::set_Speed(float value)
{
    Speed = value;
};

float Mob::get_Speed()
{
    return Speed;
};

Vector2 Mob::clipPos(Vector2 pos)
{
    if (pos.x <= 0)
        return pos.rotated(Math_PI / 2);
    if (pos.y <= 0)
        return pos.rotated(Math_PI / 2);
    if (pos.x >= screen_size.x)
        return pos.rotated(Math_PI / 2);
    if (pos.x >= screen_size.y)
        return pos.rotated(Math_PI / 2);
};
