#include "State.h"

class FinishedState : public State
{
private:
    virtual void _Update(Tetris* tetris);
    virtual void _Render(Tetris* tetris);
};
