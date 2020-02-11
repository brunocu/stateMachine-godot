#ifndef STATE_H
#define STATE_H

#include <Godot.hpp>
#include <Sprite.hpp>
#include <AnimationPlayer.hpp>
#include <RandomNumberGenerator.hpp>

namespace godot
{

class State
{
protected:
	Sprite* _sprite;
	AnimationPlayer* _player;
	RandomNumberGenerator* _rng;
	Vector2 _dir;

public:
	State();
	State(Node* skin);
	~State();

	void reflect(Vector2 normal);

	virtual Vector2 HandleUpdate(float delta);
	virtual State* collisionSignal(Node2D* node);
};

}

#endif