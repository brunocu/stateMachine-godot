#ifndef WANDERSTATE_H
#define WANDERSTATE_H

#include <Godot.hpp>

#include "State.h"

namespace godot
{

class WanderState : public State
{
private:
	using State::_sprite;
	using State::_player;
	using State::_rng;
	using State::_dir;
	using State::currState;
	float wanderAngle;

public:
	WanderState();
	WanderState(Node* skin);

	Vector2 handleUpdate(float delta);

	StateList collisionSignal(Node2D* node);
};

}

#endif