#include <cmath>
#include "RectTrapezium.h"
#include "geometryExceptions.h"

std::string RectTrapezium::getName() const {
    return "RECTRAPEZIUM";
}

double RectTrapezium::getArea() const noexcept {
    return 0.5 * (bottomBase_ + topBase_) * height_;
}

FrameRectangle RectTrapezium::getFrameRectangle() const {
    double width = std::max(bottomBase_, topBase_);
    Point centerPoint = Point(bottomLeftPoint_);
    centerPoint.move(width / 2.0, height_ / 2.0);
    return FrameRectangle(width, height_, centerPoint);
}

void RectTrapezium::move(const Point &point) {
    double midline = (bottomBase_ + topBase_) / 2.0;
    bottomLeftPoint_.move(point.getX() - midline / 2.0, point.getY() - height_ / 2.0);
}

void RectTrapezium::move(double deltaX, double deltaY) {
    bottomLeftPoint_.move(deltaX, deltaY);
}

void RectTrapezium::scale(double k) {
    double midline = (bottomBase_ + topBase_) / 2.0;
    double centerX = bottomLeftPoint_.getX() + midline / 2.0;
    double centerY = bottomLeftPoint_.getY() + height_ / 2.0;

    double deltaX = (bottomLeftPoint_.getX() - centerX) * k;
    double deltaY = (bottomLeftPoint_.getY() - centerY) * k;
    bottomLeftPoint_.move(deltaX, deltaY);

    topBase_ *= k;
    bottomBase_ *= k;
    height_ *= k;
}

Shape *RectTrapezium::clone() const {
    Shape *result = nullptr;
    try {
        result = new RectTrapezium(*this);
    }
    catch (std::bad_alloc &e) {
        throw NoMemoryToAllocateException();
    }
    return result;
}
