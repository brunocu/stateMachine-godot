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
    // Load random skin
    const char* skinIdx = skins[rand() % 3].c_str();
    char path[30];
    snprintf(path, 30, "res://scenes/skins/%s.tscn", skinIdx);
    ResourceLoader* ReLo = ResourceLoader::get_singleton();
    Ref<PackedScene> skinNode = ReLo->load(path);
    Node* skin = skinNode->instance();
    add_child(skin);
    _state = new IdleState(skin);
};

void Mob::_process(float delta)
{
    Vector2 currPos = get_position();
    // Function pointer
    // God help me
    statePtr updateFn = &State::HandleUpdate;
    Vector2 deltaPos = (_state->*updateFn)(delta);
};

void godot::Mob::set_Speed(float value)
{
    Speed = value;
};

float godot::Mob::get_Speed()
{
    return Speed;
};
