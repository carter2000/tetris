#include "State.h"

State::State()
{
}

State::~State()
{
}

void State::Update(Tetris* tetris)
{
    _Update(tetris);
}

void State::Render(Tetris* tetris)
{
    _Render(tetris);
}

void State::Enter(Tetris* tetris)
{
    _Enter(tetris);
}

void State::Exit()
{
    _Exit();
}

void State::_Update(Tetris*)
{
}

void State::_Render(Tetris*)
{
}

void State::_Enter(Tetris*)
{
}

void State::_Exit()
{
}
