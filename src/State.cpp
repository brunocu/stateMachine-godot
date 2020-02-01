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
	Godot::print("State exists!\nAnimationPlayer bound");
}
