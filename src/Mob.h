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
public:
    float speed;
public:
    static void _register_methods();

    void _init();
    void _ready();
    void _process(float delta);
};

}

#endif