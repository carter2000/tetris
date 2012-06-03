#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../DataDefines.h"

class Panel; 

class Shape
{
public:
    Shape();
    virtual ~Shape();

    void Init();
    void Clamp(Panel* panel);
    void Shift(const Panel* panel);
    bool MoveDown(const Panel* panel);
    bool MoveLeft(const Panel* panel);
    bool MoveRight(const Panel* panel);
    bool IsBlock(int iRow, int iColumn) const;
    int GetMinX() const;
    int GetMaxX() const;

private:
    virtual void _InitData() = 0;
    virtual void _Shift(const Panel* panel) = 0;

private:
    bool _Move(const Panel* panel, int xshift, int yshift);

protected:
    Grid m_data[SHAPE_GRIDS];
};

#endif
