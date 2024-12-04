#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "Shape.h"
#include "geometryExceptions.h"

class Rectangle : public Shape {
public:
    Rectangle(const Point &bottomLeftPoint, const Point &topRightPoint) :
            bottomLeftPoint_(bottomLeftPoint),
            topRightPoint_(topRightPoint) {
            if (bottomLeftPoint_.getX() >= topRightPoint_.getX() || bottomLeftPoint_.getY() >= topRightPoint_.getY()) {
                throw InvalidRectangleException();
            }
    }

    std::string getName() const override;

    double getArea() const override;

    FrameRectangle getFrameRectangle() const override;

    void move(const Point &point) override;

    void move(double deltaX, double deltaY) override;

    void scale(double k) override;

    Shape *clone() const override;

    double getWidth() const;

    double getHeight() const;

    friend std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle);

private:
    Point bottomLeftPoint_;
    Point topRightPoint_;
};

#endif //RECTANGLE_H
