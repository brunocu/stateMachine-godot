#ifndef IDLESTATE_H
#define IDLESTATE_H

#include <Godot.hpp>

#include "State.h"

namespace godot
{

class IdleState : public State
{
private:
	using State::_player;
	using State::dir;

public:
	IdleState();
	IdleState(Node* skin);

	Vector2 HandleUpdate(float delta);
};

}

#endif