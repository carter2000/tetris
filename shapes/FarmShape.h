#ifndef __SHAPES_FARMSHAPE_H__
#define __SHAPES_FARMSHAPE_H__

#include "Shape.h"

class FarmShape : public Shape
{
private:
    /// Shape
    virtual void _InitData();
    virtual void _Shift(const Panel* panel);
};

#endif
