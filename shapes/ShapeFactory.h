#ifndef __SHAPES_SHAPEFACTORY_H__
#define __SHAPES_SHAPEFACTORY_H__

class Shape;

class ShapeFactory
{
public:
    static Shape* CreateRandomShape();
};

#endif
