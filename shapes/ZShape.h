#ifndef __SHAPES_ZSHAPE_H__
#define __SHAPES_ZSHAPE_H__

#include "Shape.h"

class ZShape : public Shape
{
private:
    /// Shape
    virtual void _InitData();
    virtual void _Shift(const Panel* panel);

private:
    void _HtoV(const Panel* panel);
    void _VtoH(const Panel* panel);
};

#endif
