#include "Shape.h"

#include "../Panel.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::Init()
{
    _InitData();
}

void Shape::Clamp(Panel* panel)
{
    for (int index = 0; index < SHAPE_GRIDS; ++index) {
        panel->Occupy(m_data[index]);
    }
}

void Shape::Shift(const Panel* panel)
{
    _Shift(panel);
}

bool Shape::MoveDown(const Panel* panel)
{
    return _Move(panel, 1, 0);
}

bool Shape::MoveLeft(const Panel* panel)
{
    return _Move(panel, 0, -1);
}

bool Shape::MoveRight(const Panel* panel)
{
    return _Move(panel, 0, 1);
}
    
bool Shape::IsBlock(int iRow, int iColumn) const
{
    for (int i = 0; i < SHAPE_GRIDS; ++i) {
        if (m_data[i].x == iRow && m_data[i].y == iColumn) {
            return true;
        }
    }
    return false;
}

int Shape::GetMinX() const
{
    int minx = m_data[0].x;
    for (int index = 1; index < SHAPE_GRIDS; ++index) {
        if (m_data[index].x < minx) {
            minx = m_data[index].x;
        }
    }
    return minx;
}

int Shape::GetMaxX() const
{
    int maxx = m_data[0].x;
    for (int index = 1; index < SHAPE_GRIDS; ++index) {
        if (m_data[index].x > maxx) {
            maxx = m_data[index].x;
        }
    }
    return maxx;
}

bool Shape::_Move(const Panel* panel, int xshift, int yshift)
{
    Grid grid;
    for (int checkIndex = 0; checkIndex < SHAPE_GRIDS; ++checkIndex) {
        grid.x = m_data[checkIndex].x + xshift;
        grid.y = m_data[checkIndex].y + yshift;
        if (!panel->IsBlank(grid)) {
            return false;
        }
    }

    for (int index = 0; index < SHAPE_GRIDS; ++index) {
        m_data[index].x += xshift;
        m_data[index].y += yshift;
    }
    
    return true;
}
