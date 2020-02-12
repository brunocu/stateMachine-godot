#include "SeekState.h"

using namespace godot;

SeekState::SeekState(Node* skin):State(skin)
{
    Godot::print("Initialized SeekState");
}

Vector2 SeekState::HandleUpdate(float delta)
{
    Vector2 currPos = _sprite->get_global_position();
    Vector2 dir = _target - currPos;
    return dir.normalized();
}