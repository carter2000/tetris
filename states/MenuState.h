#ifndef __STATES_MENUSTATE_H__
#define __STATES_MENUSTATE_H__

#include "State.h"

class MenuState : public State
{
private:
    virtual void _Update(Tetris* tetris);
    virtual void _Render(Tetris* tetris);
};

#endif
