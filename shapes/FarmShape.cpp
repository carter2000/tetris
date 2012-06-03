#include "FarmShape.h"

void FarmShape::_InitData()
{
    int row = 2;
    int column = (PANEL_WIDTH - 1) / 2;
    m_data[0].x = row;
    m_data[0].y = column;
    m_data[1].x = row;
    m_data[1].y = column + 1;
    m_data[2].x = row + 1;
    m_data[2].y = column;
    m_data[3].x = row + 1;
    m_data[3].y = column + 1;
}

void FarmShape::_Shift(const Panel*)
{
}
