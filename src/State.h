#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <AnimationPlayer.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot
{

const Vector2 ZERO { Vector2(0,0) };

enum class StateList {
	Invalid,
	WanderState,
	SeekState,
	EatState
};

class State
{
protected:
	Sprite* _sprite;
	AnimationPlayer* _player;
	RandomNumberGenerator* _rng;
	Node2D* _target;
	Vector2 _dir;
	StateList currState;

public:
	State();
	State(Node* skin);
	~State();

	void reflect(Vector2 normal);

	virtual Vector2 handleUpdate(float delta);
	virtual StateList collisionSignal(Node2D* node);
	virtual StateList hitboxEnter(Node2D* node);
	virtual StateList hitboxLeft(Node2D* node);

	void set_target(Node2D* target);
	Node2D* get_target();
	StateList get_state();
};

}

#endif