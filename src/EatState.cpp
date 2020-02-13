#include "EatState.h"

using namespace godot;

EatState::EatState(Node* skin) :State(skin)
{
	currState = StateList::EatState;
	_player->play("eating");
	_time = 0;
	Godot::print("Initialized EatState");
}

Vector2 EatState::handleUpdate(float delta)
{
	_time += delta;
	if (_time > 5)
	{
		_target->queue_free();
		Godot::print("Ate");
	}
	return ZERO;
}

StateList EatState::hitboxLeft(Node2D* node)
{
	String name = node->get_name();
	StateList newState = currState;
	if (name.find("Food"))
		newState = StateList::WanderState;
	return newState;
}