#include "State.h"

using namespace godot;

State::State(Mob* mob, Node* skin)
{
	// get root Node and set default speed
	_master = mob;
	float* _speed = &_master->speed;
	// get animation player
	Node* player = skin->get_child(2);
	_player = Node::cast_to<AnimationPlayer>(player);
	Godot::print("State exists!");
}
