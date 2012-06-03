#include "LineShape.h"

#include "../Panel.h"

LineShape::LineShape()
{
}

LineShape::~LineShape()
{
}

void LineShape::_InitData()
{
    int row = 0;
    int column = (PANEL_WIDTH - 1) / 2;
    for (int index = 0; index < SHAPE_GRIDS; ++index) {
        m_data[index].x = row;
        m_data[index].y = column;
        ++row;
    }
}

void LineShape::_Shift(const Panel* panel)
{
    if (m_data[0].x == m_data[1].x) {
        HtoV(panel);
    }
    else {
        VtoH(panel);
    }
}

void LineShape::HtoV(const Panel* panel)
{
    Grid start;
    Grid end;
    start.y = m_data[0].y;
    end.y = m_data[SHAPE_GRIDS - 1].y;

    int basex = m_data[0].x - (SHAPE_GRIDS - 1) / 2;
    int startxs[] = { basex, basex - 1, basex + 1, basex - 2 };
    int xindex = 0;
    for (; xindex < sizeof(startxs)/sizeof(int); ++xindex) {
        start.x = startxs[xindex];
        end.x = start.x + SHAPE_GRIDS - 1;
        if (panel->IsBlank(start, end)) {
            break;
        }
    }
    
    if (xindex < SHAPE_GRIDS) {
        int newy = m_data[0].y + (SHAPE_GRIDS - 1) / 2;
        for (int index = 0; index < SHAPE_GRIDS; ++index) {
            m_data[index].x = startxs[xindex] + index;
            m_data[index].y = newy;
        }
    }
}

void LineShape::VtoH(const Panel* panel)
{
    Grid start;
    Grid end;

    start.x = m_data[0].x;
    end.x = m_data[SHAPE_GRIDS - 1].x;

    int basey = m_data[0].y - (SHAPE_GRIDS - 1) / 2;
    int startys[] = { basey, basey - 1, basey + 1, basey -2 };
    int yindex = 0;
    for (; yindex < sizeof(startys)/sizeof(int); ++yindex) {
        start.y = startys[yindex];
        end.y = start.y + SHAPE_GRIDS - 1;
        if (panel->IsBlank(start, end)) {
            break;
        }
    }
    
    if (yindex < SHAPE_GRIDS) {
        int newx = m_data[0].x + SHAPE_GRIDS / 2;
        for (int index = 0; index < SHAPE_GRIDS; ++index) {
            m_data[index].x = newx;
            m_data[index].y = startys[yindex] + index;
        }
    }
}
