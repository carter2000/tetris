#include "MenuState.h"

#include "../Tetris.h"

void MenuState::_Update(Tetris* tetris)
{
    if (tetris->IsContinueKeyPressed()) {
        tetris->ChangeState(ST_PLAYING);
    }
}

void MenuState::_Render(Tetris* tetris)
{
    tetris->DrawMenu();
}
