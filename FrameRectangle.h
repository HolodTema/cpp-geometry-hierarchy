#ifndef FRAME_RECTANGLE_H
#define FRAME_RECTANGLE_H

#include "Point.h"
#include "geometryExceptions.h"

class FrameRectangle {
public:
    FrameRectangle(double width, double height, const Point &pos):
        width_(width),
        height_(height),
        pos_(pos)
    {
        if (width <= 0 || height <= 0) {
            throw InvalidFrameRectangleException();
        }
    }

    double getWidth() const noexcept {
        return width_;
    }

    double getHeight() const noexcept {
        return height_;
    }

    Point getBottomLeftPoint() const noexcept;

    Point getTopRightPoint() const noexcept;

    const Point& getPos() const noexcept {
        return pos_;
    }
private:
    double width_;
    double height_;
    Point pos_;
};

#endif //FRAME_RECTANGLE_H
