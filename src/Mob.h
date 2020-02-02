#ifndef MOB_H
#define MOB_H

#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>

#include "State.h"

namespace godot{

class Mob : public Node2D{
    GODOT_CLASS(Mob, Node2D)

private:
    std::vector<std::string> skins;
    State* _state;
    float Speed;
    float time;
    char buffer[50];
public:
    static void _register_methods();

    void _init();
    void _ready();
    void _process(float delta);

    void set_Speed(float value);
    float get_Speed();
};

}

#endif