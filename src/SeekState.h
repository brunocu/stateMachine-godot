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
	using State::_dir;
	Vector2 target;

public:
	SeekState(Sprite* sprite, AnimationPlayer* player, Vector2 dir);

	Vector2 HandleUpdate(float delta);
};
}

#endif