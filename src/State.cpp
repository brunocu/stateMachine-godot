#include "State.h"

using namespace godot;

State::State()
{
	_player = NULL;
}

State::State(Node* skin)
{
	// get animation player
	Node* player = skin->get_child(2);
	_player = Node::cast_to<AnimationPlayer>(player);
	Godot::print("Base initialized");
}

void State::reflect(Vector2 normal)
{
	dir = dir - 2.0 * dir.dot(normal) * normal;
}

Vector2 State::HandleUpdate(float delta)
{
	// Standard method
	// Returns direction of movement (i.e. Unit Vector)
	// Overriden by particular States
	return Vector2();
}