#ifndef __STATE_H__
#define __STATE_H__

class Tetris;

enum StateType
{
    ST_SPLASH = 0,
    ST_MENU,
    ST_PLAYING,
    ST_FINISHED,
    ST_MAX,
};

class State
{
public:
    State();
    virtual ~State();

    void Update(Tetris* tetris);
    void Render(Tetris* tetris);
    void Enter(Tetris* tetris);
    void Exit();

private:
    virtual void _Update(Tetris* tetris);
    virtual void _Render(Tetris* tetris);
    virtual void _Enter(Tetris* tetris);
    virtual void _Exit();
};

#endif
