#include "State.h"

using namespace godot;

State::State()
{
	_player = NULL;
};

State::State(Node* skin)
{
	// get animation player
	Node* player = skin->get_child(2);
	_player = Node::cast_to<AnimationPlayer>(player);
	Godot::print("Base initialized");
};

Vector2 State::HandleUpdate(float delta)
{
	// Standard method
	// Returns direction of movement (i.e. Unit Vector)
	// Overriden by particular States
	return Vector2();
};