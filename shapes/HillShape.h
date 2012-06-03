#ifndef __SHAPES_HILLSHAPE_H__
#define __SHAPES_HILLSHAPE_H__

#include "Shape.h"

class HillShape : public Shape
{
private:
    /// Shape
    virtual void _InitData();
    virtual void _Shift(const Panel* panel);

private:
    void _UtoL(const Panel* panel);
    void _LtoD(const Panel* panel);
    void _DtoR(const Panel* panel);
    void _RtoU(const Panel* panel);
};

#endif
