#include "Tetris.h"

#include "Panel.h"
#include "engine/GameEngine.h"
#include "states/StateFactory.h"

#define NULL 0

Tetris::Tetris(GameEngine* engine)
: _panel(NULL)
, _engine(engine)
, _cur_state(NULL)
{
    _panel = new Panel();
    _states[ST_SPLASH] = StateFactory::Create(ST_SPLASH);
    _states[ST_MENU] = StateFactory::Create(ST_MENU);
    _states[ST_PLAYING] = StateFactory::Create(ST_PLAYING);
    _states[ST_FINISHED] = StateFactory::Create(ST_FINISHED);
}

Tetris::~Tetris()
{
    delete _panel;
    for (int i = ST_SPLASH; i < ST_MAX; ++i) {
        delete _states[i];
    }
}

void Tetris::Start()
{
    _cur_state = _states[ST_SPLASH];
    _cur_state->Enter(this);
}

void Tetris::UpdatePanel(bool left, bool right, bool down, bool shift)
{
    if (IsFinished()) {
        return;
    }

    if (left) {
        _panel->MoveLeft();
    }

    if (right) {
        _panel->MoveRight();
    }

    if (shift) {
        _panel->Shift();
    }

    if (down) {
        _panel->MoveDown();
    }
}

void Tetris::UpdateFrame()
{
    _cur_state->Update(this);
}

void Tetris::UpdateRender()
{
    _cur_state->Render(this);
}

void Tetris::ChangeState(StateType state)
{
    if (_cur_state != NULL) {
        _cur_state->Exit();
    }

    _cur_state = _states[state];
    _cur_state->Enter(this);
}

static const int DS_PANEL_START_X = 100;
static const int DS_PANEL_START_Y = 100;
static const int DS_GRID_LENGTH = 20;
static const char* DS_ENTER_TIPS = "press enter to continue";

void Tetris::DrawPanel()
{
    const int start_x = DS_PANEL_START_X;
    const int start_y = DS_PANEL_START_Y;
    const int grid_length = DS_GRID_LENGTH;
    int right_x = start_y + PANEL_WIDTH * grid_length;
    int bottom_y = start_x + (PANEL_HEIGHT - PANEL_RESERVE) * grid_length;
    _engine->PreparePen(2, GE_PS_SOLID, Color(255, 255, 255));
    _engine->DrawLine(start_x, start_y, right_x, start_y);
    _engine->DrawLine(right_x, start_y, right_x, bottom_y);
    _engine->DrawLine(right_x, bottom_y, start_x, bottom_y);
    _engine->DrawLine(start_x, bottom_y, start_x, start_y);
    _engine->ReleasePen();

    _engine->PreparePen(1, GE_PS_SOLID, Color(255, 255, 255));
    for (int i = 1; i < PANEL_HEIGHT - PANEL_RESERVE; ++i) {
        int y = start_y + i * grid_length;
        _engine->DrawLine(start_x, y, right_x, y);
    }
    for (int j = 1; j < PANEL_WIDTH; ++j) {
        int x = start_x + j * grid_length;
        _engine->DrawLine(x, start_y, x, bottom_y);
    }
    _engine->ReleasePen();

    _engine->PrepareBrush(Color(0, 255, 0));
    for (int row = 0; row < PANEL_SHOW_HEIGHT; ++row) {
        for (int column = 0; column < PANEL_WIDTH; ++column) {
            if (IsDirty(row, column)) {
                int sx = start_x + column * grid_length + 1;
                int sy = start_y + row * grid_length + 1;
                int ex = sx + grid_length - 1;
                int ey = sy + grid_length - 1;
                _engine->DrawRect(sx, sy, ex, ey);
            }
        }
    }
    _engine->ReleaseBrush();
    
    _engine->DrawText(right_x + 20, start_y + 100, 20, Color(0,255,0), "Level: %d", _panel->GetLevel());

    _engine->DrawText(right_x + 20, start_y + 150, 20, Color(0,255,0), "Score: %d", _panel->GetScore());
}    
    
void Tetris::DrawGameOver()
{
    int x = DS_PANEL_START_X;
    int y = DS_PANEL_START_Y + DS_GRID_LENGTH * PANEL_SHOW_HEIGHT/ 2 - 45;
    int tip_y = DS_PANEL_START_Y + DS_GRID_LENGTH*PANEL_SHOW_HEIGHT + 25;
    Color color(255, 0, 0);
    _engine->DrawText(x, y, 45, color, "Game Over!");
    _engine->DrawText(x, tip_y, 25, color, DS_ENTER_TIPS);
}

void Tetris::DrawMenu()
{
    int iSize = static_cast<int>(2.5f * DS_GRID_LENGTH);
    int y = DS_PANEL_START_Y + DS_GRID_LENGTH * PANEL_SHOW_HEIGHT/ 2 - iSize;
    _engine->DrawText(10, y, iSize, Color(255, 0, 255), DS_ENTER_TIPS);
}
    
void Tetris::DrawSplash()
{
    int x = _engine->RandomInt(_engine->GetIntValue(GEK_SCREENWIDTH));
    int y = _engine->RandomInt(_engine->GetIntValue(GEK_SCREENHEIGHT));
    int size = _engine->RandomInt(150);
    int r = _engine->RandomInt(255);
    int g = _engine->RandomInt(255);
    int b = _engine->RandomInt(255);
    _engine->DrawText(x, y, size, Color(r, g, b), "splash");

}

bool Tetris::IsFinished() const
{
    return _panel->IsFinished();
}

bool Tetris::IsDirty(int iRow, int iColumn) const
{
    return _panel->IsDirty(iRow, iColumn);
}

bool Tetris::IsLeftKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_LEFT) || _engine->IsKeyDown(GE_KC_A);
}

bool Tetris::IsRightKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_RIGHT) || _engine->IsKeyDown(GE_KC_D);
}

bool Tetris::IsDownKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_DOWN) || _engine->IsKeyDown(GE_KC_S);
}

bool Tetris::IsShiftKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_UP) || _engine->IsKeyDown(GE_KC_W);
}

bool Tetris::IsPauseKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_P);
}

bool Tetris::IsRestartKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_R);
}

bool Tetris::IsContinueKeyPressed() const
{
    return _engine->IsKeyDown(GE_KC_ENTER);
}

int Tetris::GetLevel()
{
    return _panel->GetLevel();
}

void Tetris::Reset()
{
    _panel->Reset();
}
