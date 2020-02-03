#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Node.hpp>
#include <AnimationPlayer.hpp>

namespace godot
{

class State
{
protected:
	AnimationPlayer* _player;
	Vector2 dir;

public:
	State();
	State(Node* skin);

	void reflect(Vector2 normal);

	virtual Vector2 HandleUpdate(float delta);
};

}

#endif