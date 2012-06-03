#ifndef __STATES_PLAYINGSTATE_H__
#define __STATES_PLAYINGSTATE_H__

#include "State.h"

class PlayingState : public State
{
public:
    PlayingState();

private:
    virtual void _Update(Tetris* tetris);
    virtual void _Render(Tetris* tetris);
    virtual void _Enter(Tetris* tetris);

private:
    bool _pause;
    int _cur_frames;
};

#endif
