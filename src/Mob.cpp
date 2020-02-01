#include "Mob.h"

#include <ResourceLoader.hpp>
#include <PackedScene.hpp>

using namespace godot;

void Mob::_register_methods()
{
    register_property<Mob, float>("Speed", &Mob::Speed, 10);
    register_method("_ready", &Mob::_ready);
    register_method("_process", &Mob::_process);
}

void Mob::_init()
{
    // Initialize variables 
    skins = {"Red", "Green", "Blue"};
}

void Mob::_ready()
{
    // Called when node enters scene tree
    // Load random skin
    const char* skinIdx = skins[ rand() % 3 ].c_str();
    char path[30];
    snprintf(path, 30, "res://scenes/skins/%s.tscn", skinIdx);
    ResourceLoader* ReLo = ResourceLoader::get_singleton();
    Ref<PackedScene> skinNode = ReLo->load(path);
    Node* skin = skinNode->instance();
    add_child(skin);
    _state = State(skin);
}

void Mob::_process(float delta)
{
    // Called every frame
}
