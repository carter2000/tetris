#ifndef __DATADEFINES_H__
#define __DATADEFINES_H__

struct Grid
{
    int x;
    int y;
};

enum
{
    SHAPE_GRIDS = 4,
    PANEL_RESERVE = 4,
    PANEL_WIDTH = 10,
    PANEL_SHOW_HEIGHT = 18,
    PANEL_HEIGHT = PANEL_SHOW_HEIGHT + PANEL_RESERVE,
};

#endif
