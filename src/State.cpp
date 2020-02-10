#include "State.h"

using namespace godot;

State::State()
{
	// This constructor shouldn't be called
	_sprite = NULL;
	_player = NULL;
	_rng = NULL;
}

State::State(Node* skin)
{
	// Initialize rng
	_rng = RandomNumberGenerator::_new();
	//get sprite
	Node* sprite = skin->get_child(0);
	_sprite = Node::cast_to<Sprite>(sprite);
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