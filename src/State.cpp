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
	// Don't use base State
	currState = StateList::Invalid;
}

State::~State()
{
	delete _sprite;
	delete _player;
	delete _rng;
}

void State::reflect(Vector2 normal)
{
	_dir = _dir - 2.0 * _dir.dot(normal) * normal;
}

Vector2 State::HandleUpdate(float delta)
{
	// Standard method
	// Returns direction of movement (i.e. Unit Vector)
	// Overriden by particular States
	return Vector2();
}

StateList State::collisionSignal(Node2D* node)
{
	return currState;
}

void State::set_target(Vector2 target)
{
	_target = target;
}

Vector2 State::get_target()
{
	return _target;
}

StateList State::get_state()
{
	return currState;
}