#ifndef EATSTATE_H
#define EATSTATE_H

#include <Godot.hpp>

#include "State.h"

namespace godot
{

class EatState : public State
{
private:
	using State::_player;
	using State::_target;
	using State::currState;
	float _time;

public:
	using State::State;
	EatState(Node* skin);

	Vector2 handleUpdate(float delta);
	StateList hitboxLeft(Node2D* node);
};
}

#endif