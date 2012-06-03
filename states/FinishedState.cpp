#include "FinishedState.h"

#include "../Tetris.h"

void FinishedState::_Update(Tetris* tetris)
{
    if (tetris->IsContinueKeyPressed()) {
        tetris->ChangeState(ST_MENU);
    }
}

void FinishedState::_Render(Tetris* tetris)
{
    tetris->DrawPanel();
    tetris->DrawGameOver();
}
