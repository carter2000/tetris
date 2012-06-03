#ifndef __SPLASHSTATE_H__
#define __SPLASHSTATE_H__

#include "State.h"

class SplashState : public State
{
public:
    SplashState();
    virtual ~SplashState();

private:
    /// State
    virtual void _Update(Tetris* tetris);
    virtual void _Render(Tetris* tetris);
    virtual void _Enter(Tetris* tetris);
    virtual void _Exit();

private:
    int _total_frames;
    int _cur_frames;
};

#endif
