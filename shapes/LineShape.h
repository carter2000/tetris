#ifndef __LINESHAPE_H__
#define __LINESHAPE_H__

#include "Shape.h"

class LineShape : public Shape
{
public:
    LineShape();
    virtual ~LineShape();

private:
    /// Shape
    virtual void _InitData();
    virtual void _Shift(const Panel* panel);

private:
    void HtoV(const Panel* panel);
    void VtoH(const Panel* panel);
};

#endif
