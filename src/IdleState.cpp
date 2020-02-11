#include "IdleState.h"

const float CIRCLE_DISTANCE = 25. / 4;
const float CIRCLE_RADIUS = 1;
const float ANGLE_CHANGE = Math_PI / 2;

using namespace godot;

IdleState::IdleState():State()
{
	dir = Vector2();
	wanderAngle = 0;
}

IdleState::IdleState(Node* skin):State(skin)
{
	_player->play("walk");
	
	dir = Vector2(1, 0);
	float rndAngle = _rng->randi() / (RAND_MAX / (2.0 * Math_PI));
	dir.set_rotation(rndAngle);
	dir.normalize();

	wanderAngle = (_rng->randi()/RAND_MAX * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5);
	Godot::print("Initialized IdleState");
}

Vector2 IdleState::HandleUpdate(float delta)
{
	// Wander Algorithm based on
	// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624
	Vector2 circleCenter = dir * CIRCLE_DISTANCE;
	Vector2 displacement = Vector2(0,-1) * CIRCLE_RADIUS;
	displacement.set_rotation(wanderAngle);
	wanderAngle += ( (_rng->randi()/RAND_MAX) * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5);
	Vector2 wanderForce = circleCenter + displacement;
	dir.set_rotation(wanderForce.angle());
	_sprite->set_flip_h( dir.x >= 0 );
	return dir;
}

State* IdleState::collisionSignal(Node2D* node)
{
	Vector2 dis = _sprite->get_global_position() - node->get_global_position();
	if (dis == Vector2())
		return NULL;
	else
		// change to Seek
	return NULL;
}