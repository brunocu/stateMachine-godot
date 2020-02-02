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
    time = 0;
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

Vector2 (State::*updatePtr)(float) = &State::HandleUpdate;

void Mob::_process(float delta)
{
    Vector2 currPos = get_position();
    // Function pointer
    // God help me
    Vector2 deltaPos = (_state->*updatePtr)(delta);
    time += delta;
    if (time >= 2)
    {
        snprintf(buffer, 50, "currPos: %0.2f,%0.2f", currPos.x, currPos.y);
        Godot::print(buffer);
        snprintf(buffer, 50, "deltaPos: %0.2f,%0.2f", deltaPos.x, deltaPos.y);
        Godot::print(buffer);
        time = 0;
    }
};

void godot::Mob::set_Speed(float value)
{
    Speed = value;
};

float godot::Mob::get_Speed()
{
    return Speed;
};
