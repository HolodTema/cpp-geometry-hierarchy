#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "FrameRectangle.h"
#include "Point.h"

class Shape {
public:
    virtual std::string getName() const = 0;

    virtual double getArea() const = 0;

    virtual FrameRectangle getFrameRectangle() const = 0;

    virtual void move(const Point& point)    = 0;

    virtual void move(double deltaX, double deltaY) = 0;

    virtual void scale(double k) = 0;

    virtual Shape* clone() const = 0;
};

#endif //SHAPE_H
