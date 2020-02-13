#include "State.h"

using namespace godot;

State::State()
{
	// This constructor shouldn't be called
	currState = StateList::Invalid;
	_sprite = NULL;
	_player = NULL;
	_rng = NULL;
	_target = NULL;
}

State::State(Node* skin)
{
	// Initialize rng
	_rng = RandomNumberGenerator::_new();
	//get sprite
	Node* sprite = skin->get_child(0);
	_sprite = Node::cast_to<Sprite>(sprite);
	// get animation player
	Node* player = skin->get_child(1);
	_player = Node::cast_to<AnimationPlayer>(player);
	// Don't use base State
	currState = StateList::Invalid;
	// init missing members
	_target = NULL;
}

State::~State()
{
	delete _sprite;
	delete _player;
	delete _rng;
	delete _target;
}

void State::reflect(Vector2 normal)
{
	_dir = _dir - 2.0 * _dir.dot(normal) * normal;
}

Vector2 State::handleUpdate(float delta)
{
	// Standard method
	// Returns direction of movement (i.e. Unit Vector)
	// Overriden by particular States
	return ZERO;
}

StateList State::collisionSignal(Node2D* node)
{
	return currState;
}

StateList State::hitboxEnter(Node2D* node)
{
	return currState;
}

StateList State::hitboxLeft(Node2D* node)
{
	return currState;
}

void State::set_target(Node2D* target)
{
	_target = target;
}

Node2D* State::get_target()
{
	return _target;
}

StateList State::get_state()
{
	return currState;
}