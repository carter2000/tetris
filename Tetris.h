#ifndef __TETRIS_H__
#define __TETRIS_H__

#include "states/State.h"

class Panel;
class GameEngine;

class Tetris
{
public:
    Tetris(GameEngine* engine);
    ~Tetris();

    void Start();
    void UpdatePanel(bool left, bool right, bool down, bool shift);
    void UpdateFrame();
    void UpdateRender();
    void ChangeState(StateType state);
    void DrawPanel();
    void DrawGameOver();
    void DrawMenu();
    void DrawSplash();

    bool IsFinished() const;
    bool IsDirty(int iRow, int iColumn) const;
    bool IsLeftKeyPressed() const;
    bool IsRightKeyPressed() const;
    bool IsDownKeyPressed() const;
    bool IsShiftKeyPressed() const;
    bool IsPauseKeyPressed() const;
    bool IsRestartKeyPressed() const;
    bool IsContinueKeyPressed() const;

    int GetLevel();
    void Reset();

private:
    Panel* _panel;
    GameEngine* _engine;
    State* _cur_state;
    State* _states[ST_MAX];
};
#endif
