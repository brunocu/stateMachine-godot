#include "SeekState.h"

using namespace godot;

SeekState::SeekState(Node* skin):State(skin)
{
    currState = StateList::SeekState;
    _player->play("walk");
    Godot::print("Initialized SeekState");
}

Vector2 SeekState::handleUpdate(float delta)
{
    Vector2 currPos = _sprite->get_global_position();
    Vector2 targetPos = _target->get_global_position();
    Vector2 dir = targetPos - currPos;
    return dir.normalized();
}

StateList SeekState::hitboxEnter(Node2D* target)
{
    String name = target->get_name();
    if (name.find("Food"))
        return StateList::EatState;
    return currState;
}