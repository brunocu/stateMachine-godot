#ifndef MOB_H
#define MOB_H

#include <vector>

#include <Godot.hpp>
#include <Area2D.hpp>
#include <Variant.hpp>

#include "State.h"

namespace godot
{

typedef Vector2 (State::*floatFn)(float);
typedef StateList (State::*nodePtrFn)(Node2D*);

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
    nodePtrFn colFn;

public:
    static void _register_methods();

    void _init();
    void _ready();
    void _process(float delta);
    void _on_Food_sighted(Variant area);

    void set_Speed(float value);
    float get_Speed();

    State* stateInit(StateList state);
};

}

#endif