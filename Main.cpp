#include "Tetris.h"
#include "engine/GameEngine.h"

bool UpdateFrame();
bool UpdateRender();

Tetris* g_tetris = NULL;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int iShowCmd)
{
    GameEngine::instance()->SetValue(GEK_LOGFILE, "tetris.log");
    GameEngine::instance()->SetValue(GEK_WINTITLE, "Tetris");
    GameEngine::instance()->SetValue(GEK_FPS, 100);
    GameEngine::instance()->SetValue(GEK_SCREENWIDTH, 465);
    GameEngine::instance()->SetValue(GEK_SCREENHEIGHT, 600);
    GameEngine::instance()->SetValue(GEK_FRAMEFUNC, &UpdateFrame);
    GameEngine::instance()->SetValue(GEK_RENDERFUNC, &UpdateRender);

    if (GameEngine::instance()->Initiate()) {
        g_tetris = new Tetris(GameEngine::instance());
        g_tetris->Start();
        GameEngine::instance()->Start();
    }

    GameEngine::instance()->Shutdown();
    return 0;
}

bool UpdateFrame()
{
    g_tetris->UpdateFrame();
    return false;
}

bool UpdateRender()
{
    g_tetris->UpdateRender();
    return false;
}
