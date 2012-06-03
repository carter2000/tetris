#include "RLShape.h"

#include "../Panel.h"

void RLShape::_InitData()
{
    int firstx = 1;
    int firsty = (PANEL_WIDTH - 1) / 2 + 1;
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx + 1;
    m_data[1].y = firsty;
    m_data[2].x = firstx + 2;
    m_data[2].y = firsty;
    m_data[3].x = firstx + 2;
    m_data[3].y = firsty - 1;
}

void RLShape::_Shift(const Panel* panel)
{
    if (m_data[0].x < m_data[1].x) {
        _UtoL(panel);
    }
    else if (m_data[0].x > m_data[1].x) {
        _DtoR(panel);
    }
    else {
        if (m_data[0].y < m_data[1].y) {
            _LtoD(panel);
        }
        else {
            _RtoU(panel);
        }
    }
}

void RLShape::_UtoL(const Panel* panel)
{
    Grid start;
    Grid end;
    start.x = m_data[0].x;
    end.x = m_data[3].x;

    int firsty = m_data[0].y;
    int ys[] = { firsty, firsty - 1, firsty - 2, firsty + 1 };
    int maxindex = sizeof(ys)/sizeof(int);
    for (int index = 0; index < maxindex; ++index) {
        start.y = ys[index];
        end.y = ys[index];
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
    firsty = ((index == 2) ? firsty - 2 : firsty - 1);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx;
    m_data[1].y = firsty + 1;
    m_data[2].x = firstx;
    m_data[2].y = firsty + 2;
    m_data[3].x = firstx + 1;
    m_data[3].y = firsty + 2;
}

void RLShape::_LtoD(const Panel* panel)
{
    Grid start;
    Grid end;
    start.y = m_data[0].y;
    end.y = m_data[3].y;

    int firstx = m_data[0].x;
    int xs[] = { firstx, firstx + 1, firstx - 1, firstx + 2 };
    int maxindex = sizeof(xs)/sizeof(xs[0]);
    for (int index = 0; index < maxindex; ++index) {
        start.x = xs[index];
        end.x = xs[index];
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

    int firsty = m_data[0].y;
    firstx = ((index == 2) ? firstx + 1 : firstx + 2);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx - 1;
    m_data[1].y = firsty;
    m_data[2].x = firstx - 2;
    m_data[2].y = firsty;
    m_data[3].x = firstx - 2;
    m_data[3].y = firsty + 1;
}

void RLShape::_DtoR(const Panel* panel)
{
    Grid start;
    Grid end;
    start.x = m_data[3].x;
    end.x = m_data[0].x;

    int firsty = m_data[0].y;
    int ys[] = { firsty, firsty + 1, firsty + 2, firsty - 1 };
    int maxindex = sizeof(ys)/sizeof(ys[0]);
    for (int index = 0; index < maxindex; ++index) {
        start.y = ys[index];
        end.y = ys[index];
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

    int firstx = m_data[0].x;
    firsty = ((index == 2) ? firsty + 2 : firsty + 1);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx;
    m_data[1].y = firsty - 1;
    m_data[2].x = firstx;
    m_data[2].y = firsty - 2;
    m_data[3].x = firstx - 1;
    m_data[3].y = firsty - 2;
}

void RLShape::_RtoU(const Panel* panel)
{
    Grid start;
    Grid end;
    start.y = m_data[3].y;
    end.y = m_data[0].y;

    int firstx = m_data[0].x;
    int xs[] = { firstx, firstx - 1, firstx - 2, firstx + 1 };
    int maxindex = sizeof(xs)/sizeof(xs[0]);
    for (int index = 0; index < maxindex; ++index) {
        start.x = xs[index];
        end.x = xs[index];
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

    int firsty = m_data[0].y;
    firstx = ((index == 2) ? firstx - 2 : firstx - 1);
    m_data[0].x = firstx;
    m_data[0].y = firsty;
    m_data[1].x = firstx + 1;
    m_data[1].y = firsty;
    m_data[2].x = firstx + 2;
    m_data[2].y = firsty;
    m_data[3].x = firstx + 2;
    m_data[3].y = firsty - 1;
}
