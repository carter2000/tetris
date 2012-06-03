#include "StateFactory.h"

#include <cassert>

#include "FinishedState.h"
#include "MenuState.h"
#include "PlayingState.h"
#include "SplashState.h"

#define NULL 0

State* StateFactory::Create(StateType type)
{
    switch (type)
    {
        case ST_SPLASH:
            return new SplashState();
        case ST_MENU:
            return new MenuState();
        case ST_PLAYING:
            return new PlayingState();
        case ST_FINISHED:
            return new FinishedState();
        default:
            assert(false);
            return NULL;
    }
}
