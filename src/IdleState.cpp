#include "IdleState.h"

#include <RandomNumberGenerator.hpp>

const float CIRCLE_DISTANCE = 10;
const float CIRCLE_RADIUS = 5;
const float ANGLE_CHANGE = Math_PI / 2;

using namespace godot;

IdleState::IdleState():State()
{
	dir = Vector2();
}

IdleState::IdleState(Node* skin):State(skin)
{
	_player->play("walk");
	
	dir = Vector2(0, 1);
	float rndAngle = rand() / (RAND_MAX / (2.0 * Math_PI));
	dir.set_rotation(rndAngle);
	dir.normalize();

	wanderAngle = (rand()/RAND_MAX * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5);
	Godot::print("Initialized IdleState");
}

Vector2 IdleState::HandleUpdate(float delta)
{
	// Wander Algorithm based on
	// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624
	Vector2 circleCenter = dir * CIRCLE_DISTANCE;
	Vector2 displacement = Vector2(0,-1) * CIRCLE_RADIUS;
	displacement.set_rotation(wanderAngle);
	wanderAngle += /*(rand()/RAND_MAX * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5)*/ Math_PI / 4;
	Vector2 wanderForce = circleCenter + displacement;
	dir.set_rotation(wanderForce.angle());
	_sprite->set_flip_h( dir.x >= 0 );
	return dir;
}