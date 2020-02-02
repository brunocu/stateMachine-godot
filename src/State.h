#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Node.hpp>
#include <AnimationPlayer.hpp>

namespace godot{

class State
{
protected:
	AnimationPlayer* _player;
public:
	State();
	State(Node* skin);

	virtual Vector2 HandleUpdate(float delta);
};

}

#endif