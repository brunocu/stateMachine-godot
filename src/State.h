#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Node.hpp>
#include <AnimationPlayer.hpp>

namespace godot{

class State
{
private:
	AnimationPlayer* _player;
public:
	State();
	State(Node* skin);
	State* handleUpdate(float delta);
};

}

#endif