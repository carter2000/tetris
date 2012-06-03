#include "ShapeFactory.h"

#include <cassert>
#include <cstdlib>

#include "FarmShape.h"
#include "HillShape.h"
#include "LineShape.h"
#include "LShape.h"
#include "RLShape.h"
#include "RZShape.h"
#include "ZShape.h"

#define NULL 0

enum ShapeType
{
    ST_LINE = 0,
    ST_FARM,
    ST_Z,
    ST_RZ,
    ST_HILL,
    ST_L,
    ST_RL,
    ST_MAX,
};

Shape* ShapeFactory::CreateRandomShape()
{
    Shape* shape = NULL;
    switch (rand() % ST_MAX) {
        case ST_LINE:
            shape = new LineShape();
            break;
        case ST_FARM:
            shape = new FarmShape();
            break;
        case ST_Z:
            shape = new ZShape();
            break;
        case ST_RZ:
            shape = new RZShape();
            break;
        case ST_HILL:
            shape = new HillShape();
            break;
        case ST_L:
            shape = new LShape();
            break;
        case ST_RL:
            shape = new RLShape();
            break;
        default:
            assert(false);
            break;
    }
    shape->Init();
    return shape;
}
