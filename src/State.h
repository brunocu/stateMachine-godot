#ifndef STATE_H
#define STATE_H

namespace godot{

class State
{
public:
    void handleUpdate(float delta);
    void handleEnter();
    void handleExit();
};

}

#endif