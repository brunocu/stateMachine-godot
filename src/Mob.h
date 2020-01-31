#ifndef MOB_H
#define MOB_H

#include <vector>

#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <AnimationPlayer.hpp>

namespace godot{

class Mob : public Node2D{
    GODOT_CLASS(Mob, Node2D)

private:
    std::vector<std::string> skins;
    Node* skin;
public:
    static void _register_methods();

    void _init();
    void _ready();
    void _process(float delta);
};

}

#endif