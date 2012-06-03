#include "Panel.h"

#include <cassert>
#include <cmath>
#include <cstdlib>

#include "shapes/Shape.h"
#include "shapes/ShapeFactory.h"

Panel::Panel()
: m_level(0)
, m_score(0)
, m_shape(0)
, m_isFinished(false)
{
    Reset();
}

Panel::~Panel()
{
    delete m_shape;
}

void Panel::Reset()
{
    m_level = 0;
    m_score = 0;
    m_isFinished = false;
    _ClearOccupied();
    _GenerateShape();
}
    
void Panel::Shift()
{
    m_shape->Shift(this);
}

void Panel::MoveDown()
{
    if (!m_shape->MoveDown(this)) {
        m_shape->Clamp(this);
        _EraseLine(m_shape->GetMinX(), m_shape->GetMaxX());
        if (!m_isFinished) {
            delete m_shape;
            _GenerateShape();
        }
    }
}

void Panel::MoveLeft()
{
    m_shape->MoveLeft(this);
}

void Panel::MoveRight()
{
    m_shape->MoveRight(this);
}

void Panel::Occupy(const Grid& grid)
{
    assert(!m_occupied[grid.x][grid.y]);
    m_occupied[grid.x][grid.y] = true;
    if (grid.x < PANEL_RESERVE) {
        m_isFinished = true;
    }
}

bool Panel::IsBlank(const Grid& grid) const
{
    if (grid.x < 0 || grid.x >= PANEL_HEIGHT ||
        grid.y < 0 || grid.y >= PANEL_WIDTH) {
        return false;
    }
    return !m_occupied[grid.x][grid.y];
}

bool Panel::IsBlank(const Grid& start, const Grid& end) const
{
    assert(start.x <= end.x);
    assert(start.y <= end.y);
    if (start.x < 0 || end.x >= PANEL_HEIGHT ||
        start.y < 0 || end.y >= PANEL_WIDTH) {
        return false;
    }

    for (int x = start.x; x <= end.x; ++x) {
        for (int y = start.y; y <= end.y; ++y) {
            if (m_occupied[x][y]) {
                return false;
            }
        }
    }

    return true;
}
    
bool Panel::IsFinished() const
{
    return m_isFinished;
}
    
bool Panel::IsDirty(int iRow, int iColumn) const
{
    iRow += PANEL_RESERVE;
    return m_occupied[iRow][iColumn] || m_shape->IsBlock(iRow, iColumn);
}
    
int Panel::GetLevel() const
{
    return m_level;
}

int Panel::GetScore() const
{
    return m_score;
}
    
void Panel::_ClearOccupied()
{
    for (int i = 0; i < PANEL_HEIGHT; ++i) {
        for (int j = 0; j < PANEL_WIDTH; ++j) {
            m_occupied[i][j] = false;
        }
    }
}

void Panel::_GenerateShape()
{
    m_shape = ShapeFactory::CreateRandomShape();
    int shift_time = ::rand() % 4;
    while (shift_time-- > 0) {
        Shift();
    }
}

void Panel::_EraseLine(int minx, int maxx)
{
    int count = 0;
    for (int checkx = minx; checkx <= maxx; ++checkx) {
        bool iserase = true;
        for (int y = 0; y < PANEL_WIDTH; ++y) {
            if (!m_occupied[checkx][y]) {
                iserase = false;
                break;
            }
        }

        if (!iserase) {
            continue;
        }

        ++count;
        for (int x = checkx - 1; x >= 0; --x) {
            int isempty = true;
            for (int y = 0; y < PANEL_WIDTH; ++y) {
                if (m_occupied[x][y]) {
                    isempty = false;
                }
                m_occupied[x + 1][y] = m_occupied[x][y];
            }

            if (isempty) {
                break;
            }
        }
    }

    if (count <= 0) {
        return;
    }

    m_score += (7 * count + pow(3, count));
    if (m_score >= ((m_level + 1) * 100 + 50 * (pow(2, m_level) - 1))) {
        ++m_level;
    }
}
