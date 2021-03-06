#include "WanderState.h"

const float CIRCLE_DISTANCE = 25. / 4;
const float CIRCLE_RADIUS = 1;
const float ANGLE_CHANGE = Math_PI / 2;

using namespace godot;

WanderState::WanderState():State()
{
	_dir = ZERO;
	wanderAngle = 0;
}

WanderState::WanderState(Node* skin):State(skin)
{
	currState = StateList::WanderState;
	_player->play("walk");
	
	_dir = Vector2(1, 0);
	float rndAngle = _rng->randi() / (RAND_MAX / (2.0 * Math_PI));
	_dir.set_rotation(rndAngle);
	_dir.normalize();

	wanderAngle = (_rng->randi()/RAND_MAX * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5);
	Godot::print("Initialized WanderState");
}

Vector2 WanderState::handleUpdate(float delta)
{
	// Wander Algorithm based on
	// https://gamedevelopment.tutsplus.com/tutorials/understanding-steering-behaviors-wander--gamedev-1624
	Vector2 circleCenter = _dir * CIRCLE_DISTANCE;
	Vector2 displacement = Vector2(0,-1) * CIRCLE_RADIUS;
	displacement.set_rotation(wanderAngle);
	wanderAngle += ( (_rng->randi()/RAND_MAX) * ANGLE_CHANGE) - (ANGLE_CHANGE * 0.5);
	Vector2 wanderForce = circleCenter + displacement;
	_dir.set_rotation(wanderForce.angle());
	return _dir;
}

StateList WanderState::collisionSignal(Node2D* node)
{
	Vector2 dis = _sprite->get_global_position() - node->get_global_position();
	if (dis == ZERO)
		return currState;
	else
		return StateList::SeekState;
}