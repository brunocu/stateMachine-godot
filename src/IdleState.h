#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <Godot.hpp>

#include "State.h"

namespace godot
{

class IdleState : public State
{
private:
	using State::_sprite;
	using State::_player;
	using State::_rng;
	using State::dir;
	float wanderAngle;

public:
	IdleState();
	IdleState(Node* skin);

	Vector2 HandleUpdate(float delta);
};

}

#endif