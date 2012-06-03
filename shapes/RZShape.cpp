#include "RZShape.h"

#include "../Panel.h"

void RZShape::_InitData()
{
    int row = 1;
    int column = (PANEL_WIDTH - 1) / 2;

    m_data[0].x = row;
    m_data[0].y = column;
    m_data[1].x = row + 1;
    m_data[1].y = column;
    m_data[2].x = row + 1;
    m_data[2].y = column + 1;
    m_data[3].x = row + 2;
    m_data[3].y = column + 1;
}

void RZShape::_Shift(const Panel* panel)
{
    if (m_data[0].x == m_data[1].x) {
        _HtoV(panel);
    }
    else {
        _VtoH(panel);
    }
}

void RZShape::_HtoV(const Panel* panel)
{ 
    Grid start;
    Grid end;
    start.y = m_data[3].y;
    end.y = m_data[0].y;
    int firstx = m_data[0].x;
    int basexs[] = { firstx, firstx + 1, firstx - 1, firstx + 2 };
    int maxindex = sizeof(basexs)/sizeof(basexs[0]);
    for (int index = 0; index < maxindex; ++index) {
        start.x = basexs[index];
        end.x = basexs[index];
        if (index < 2) {
            if (!panel->IsBlank(start, end)) {
                return;
            }
        }
        else {
            if (panel->IsBlank(start, end)) {
                break;
            }
        } 
    }

    if (index >= maxindex) {
        return;
    }

    int firsty = m_data[0].y - 2;
    firstx = ((index == 2) ? firstx - 1 : firstx);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx + 1;
    m_data[1].y = firsty;
    m_data[2].x = firstx + 1;
    m_data[2].y = firsty + 1;
    m_data[3].x = firstx + 2;
    m_data[3].y = firsty + 1;
}
    
void RZShape::_VtoH(const Panel* panel)
{
    Grid start;
    Grid end;
    start.x = m_data[0].x;
    end.x = m_data[3].x;
    int firsty = m_data[0].y;
    int baseys[] = { firsty, firsty + 1, firsty + 2, firsty - 1 };
    int maxindex = sizeof(baseys)/sizeof(baseys[0]);
    for (int index = 0; index < maxindex; ++index) {
        start.y = baseys[index];
        end.y = baseys[index];
        if (index < 2) {
            if (!panel->IsBlank(start, end)) {
                return;
            }
        }
        else {
            if (panel->IsBlank(start, end)) {
                break;
            }
        }
    }

    if (index >= maxindex) {
        return;
    }

    int firstx = m_data[0].x + 1;
    firsty = ((index == 2) ? firsty + 2 : firsty + 1);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx;
    m_data[1].y = firsty - 1;
    m_data[2].x = firstx + 1;
    m_data[2].y = firsty - 1;
    m_data[3].x = firstx + 1;
    m_data[3].y = firsty - 2;
}
