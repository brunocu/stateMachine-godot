#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <AnimationPlayer.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot
{

enum class StateList {
	Invalid,
	IdleState,
	SeekState
};

class State
{
protected:
	Sprite* _sprite;
	AnimationPlayer* _player;
	RandomNumberGenerator* _rng;
	Vector2 _dir;
	Vector2 _target;
	StateList currState;

public:
	State();
	State(Node* skin);
	~State();

	void reflect(Vector2 normal);

	virtual Vector2 HandleUpdate(float delta);
	virtual StateList collisionSignal(Node2D* node);

	void set_target(Vector2 target);
	Vector2 get_target();
	StateList get_state();
};

}

#endif