#ifndef __STATES_STATEFACTORY_H__
#define __STATES_STATEFACTORY_H__

#include "State.h"

class StateFactory
{
public:
    static State* Create(StateType type);
};

#endif
