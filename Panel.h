#ifndef __PANEL_H__

#include "DataDefines.h"

class Shape;

class Panel
{
public:
    Panel();
    ~Panel();

    void Reset();
    void Shift();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void Occupy(const Grid& grid);
    bool IsBlank(const Grid& grid) const;
    bool IsBlank(const Grid& start, const Grid& end) const;
    bool IsFinished() const;
    bool IsDirty(int iRow, int iColumn) const;

    int GetLevel() const;
    int GetScore() const;

private:
    void _ClearOccupied();
    void _GenerateShape();
    void _EraseLine(int minx, int maxx);

private:
    int m_level;
    int m_score;
    bool m_isFinished;
    Shape* m_shape;
    bool m_occupied[PANEL_HEIGHT][PANEL_WIDTH];
};

#endif
