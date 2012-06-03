#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__

#include <windows.h>

enum GAME_ENGINE_KEY
{
    GEK_LOGFILE,
    GEK_FPS,
    GEK_WINTITLE,
    GEK_SCREENWIDTH,
    GEK_SCREENHEIGHT,
    GEK_EXITFUNC,
    GEK_FRAMEFUNC,
    GEK_RENDERFUNC,
};

enum KeyCode
{
    GE_KC_ENTER = 0x0D,
    GE_KC_A = 0x41,
    GE_KC_D = 0x44,
    GE_KC_P = 0x50,
    GE_KC_R = 0x52,
    GE_KC_S = 0x53,
    GE_KC_W = 0x57,
    GE_KC_LEFT = 0x25,
    GE_KC_UP = 0x26,
    GE_KC_RIGHT = 0x27,
    GE_KC_DOWN = 0x28,
    GE_KC_SPACE = 0x20,
};

enum PenStyle
{
    GE_PS_SOLID = 0,
    GE_PS_DASH = 1,
    GE_PS_DOT = 2,
    GE_PS_DASHDOT = 3,
};

struct Color
{
    Color(int r, int g, int b) : R(r), G(g), B(b)
    {
    }

    int R;
    int G;
    int B;
};

class GameEngine
{
private:
    GameEngine();

public:
    ~GameEngine();

    bool Initiate();
    void Shutdown();
    bool Start();

    void RandomSeed(int iSeed = 0);
    int RandomInt(int iMax);
    int RandomInt(int iMin, int iMax);

    void ChangeFocus(bool bActive);
    void BuildEvent(int iType, int iKey, int iScan, bool isRepeated);
    bool IsKeyUp(KeyCode eCode) const;
    bool IsKeyDown(KeyCode eCode) const;

    void Log(const char* szFormat, ...);

    void SetValue(GAME_ENGINE_KEY eKey, int iValue);
    void SetValue(GAME_ENGINE_KEY eKey, const char* szValue);
    void SetValue(GAME_ENGINE_KEY eKey, bool (*pfunc)());

    int GetIntValue(GAME_ENGINE_KEY eKey);

    bool CallFunc(GAME_ENGINE_KEY eKey);

    void DrawText(int x, int y, int iSize, const Color& color, const char* pszFromat, ...);

    void DrawLine(int iStartX, int iStartY, int iEndX, int iEndY);
    void DrawRect(int iStartX, int iStartY, int iEndX, int iEndY);
    void PreparePen(int iWidth, PenStyle eStyle, const Color& color);
    void ReleasePen();
    void PrepareBrush(const Color& color);
    void ReleaseBrush();

public:
    static GameEngine* instance();

private:
    void _InputInit();
    void _ClearEvents();
    bool _CallRenderFunc();
    
private:
    bool _bActive;

    int _iSeed;
    int _iLastTime;
    int _iFixedDelta;
    int _iScreenWidth;
    int _iScreenHeight;

    HWND _hWnd;
    HDC _hDC;
    HPEN _hPen;
    HBRUSH _hBrush;
    HBRUSH _hBackBrush;
    HDC _hMemDC;
    HBITMAP _hBmp;
    HINSTANCE _hInstance;
    RECT _rcClient;

    char _szError[256];
    char _szWinTitle[256];
    char _szLogFile[MAX_PATH];

    char _keys[256];

    bool (*_procExitFunc)();
    bool (*_procFrameFunc)();
    bool (*_procRenderFunc)();
};

#endif
