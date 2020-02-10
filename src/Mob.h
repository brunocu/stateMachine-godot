#ifndef MOB_H
#define MOB_H

#include <vector>

#include <Godot.hpp>
#include <Node2D.hpp>

#include "State.h"

namespace godot
{

typedef Vector2 (State::*floatFn)(float);

class Mob : public Node2D
{
    GODOT_CLASS(Mob, Node2D)

private:
    std::vector<std::string> skins;
    float Speed;
    Vector2 screen_size;

private:
    State* _state;
    floatFn updateFn;

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