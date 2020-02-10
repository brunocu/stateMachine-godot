#include "IdleState.h"

using namespace godot;

IdleState::IdleState():State()
{
	dir = Vector2();
}

IdleState::IdleState(Node* skin):State(skin)
{
	_player->play("walk");
	Godot::print("Initialized IdleState");

	dir = Vector2(1, 1);
	dir.normalize();
}

Vector2 IdleState::HandleUpdate(float delta)
{
	_sprite->set_flip_h( dir.x >= 0 );
	return dir;
}