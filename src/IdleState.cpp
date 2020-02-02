#include "IdleState.h"

using namespace godot;

IdleState::IdleState():State()
{
	dir = Vector2();
	Godot::print("Initialized default IdleState");
};

IdleState::IdleState(Node* skin):State(skin)
{
	_player->play("walk");
	Godot::print("Initialized IdleState");
};

Vector2 IdleState::HandleUpdate(float delta)
{
	dir = Vector2(1, 1);
	dir.normalize();
	return dir;
};