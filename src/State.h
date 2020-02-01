#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Node.hpp>
#include <AnimationPlayer.hpp>

namespace godot{

class State
{
private:
	// private
	Mob* _master;
	AnimationPlayer* _player;
	Vector2 direction;
	float* _speed;
public:
	// public
	State(Mob* mob, Node* skin);
	State* handleUpdate(float delta);
};

}

#endif