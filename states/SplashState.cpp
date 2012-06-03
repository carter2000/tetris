#include "SplashState.h"

#include <cassert>

#include "../Tetris.h"

SplashState::SplashState()
: _cur_frames(0)
, _total_frames(300)
{
}

SplashState::~SplashState()
{
}

void SplashState::_Update(Tetris* tetris)
{
    if (_cur_frames >= _total_frames) {
        tetris->ChangeState(ST_MENU);
    }

    ++_cur_frames;
}

void SplashState::_Render(Tetris* tetris)
{
    tetris->DrawSplash();
}

void SplashState::_Enter(Tetris*)
{
    _cur_frames = 0;
}

void SplashState::_Exit()
{
    assert(_cur_frames >= _total_frames);
}
