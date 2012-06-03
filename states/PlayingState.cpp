#include "PlayingState.h"

#include <cassert>

#include "../DataDefines.h"
#include "../Tetris.h"

PlayingState::PlayingState()
: _pause(false)
, _cur_frames(0)
{
}

void PlayingState::_Update(Tetris* tetris)
{
    static int s_level_frames[] = { 100, 70, 50, 40, 30, 20, 10, 5, 4, 3, 2 };
    int max_level = sizeof(s_level_frames)/sizeof(int);
    int cur_level = tetris->GetLevel();
    int vir_level = (cur_level < max_level) ? cur_level : max_level - 1;

    if (tetris->IsFinished()) {
        tetris->ChangeState(ST_FINISHED);
        return;
    }
    
    if (tetris->IsRestartKeyPressed()) {
        tetris->ChangeState(ST_MENU);
        return;
    }

    if (tetris->IsPauseKeyPressed()) {
        _pause = !_pause;
    }

    if (_pause) {
        return;
    }

    if (_cur_frames > s_level_frames[vir_level]) {
        tetris->UpdatePanel(false, false, true, false);
        _cur_frames = 0;
    }

    bool left = tetris->IsLeftKeyPressed();
    bool right = tetris->IsRightKeyPressed();
    bool down = tetris->IsDownKeyPressed();
    bool shift = tetris->IsShiftKeyPressed();
    tetris->UpdatePanel(left, right, down, shift);

    ++_cur_frames;
}

void PlayingState::_Render(Tetris* tetris)
{
    tetris->DrawPanel();
}
    
void PlayingState::_Enter(Tetris* tetris)
{
    _cur_frames = 0;
    _pause = false;
    tetris->Reset();
}
