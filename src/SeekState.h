#ifndef SEEKSTATE_H
#define SEEKSTATE_H

#include<Godot.hpp>
#include<Sprite.hpp>
#include<AnimationPlayer.hpp>

#include "State.h"

namespace godot
{
class SeekState : public State
{
private:
	using State::_sprite;
	using State::_player;
	using State::_target;

public:
	using State::State;
	SeekState(Node* skin);

	Vector2 handleUpdate(float delta);

	StateList hitboxEnter(Node2D* target);
};
}

#endif