#include <iostream>
#include "Rectangle.h"
#include "geometryExceptions.h"

std::string Rectangle::getName() const {
    return "RECTANGLE";
}

FrameRectangle Rectangle::getFrameRectangle() const {
    Point centerPoint = Point(bottomLeftPoint_);
    centerPoint.move(getWidth() / 2.0, getHeight() / 2.0);
    return FrameRectangle(getWidth(), getHeight(), centerPoint);
}

double Rectangle::getArea() const {
    return getWidth() * getHeight();
}

void Rectangle::move(double deltaX, double deltaY) {
    topRightPoint_.move(deltaX, deltaY);
    bottomLeftPoint_.move(deltaX, deltaY);
}

void Rectangle::move(const Point &point) {
    double width = getWidth();
    double height = getHeight();
    topRightPoint_ = Point(point.getX() + width / 2.0, point.getY() - height / 2.0);
    bottomLeftPoint_ = Point(point.getX() - width / 2.0, point.getY() + height / 2.0);
}

Shape *Rectangle::clone() const {
    Shape *result = nullptr;
    try {
        result = new Rectangle(*this);
    }
    catch (std::bad_alloc) {
        throw NoMemoryToAllocateException();
    }
    return result;
}

void Rectangle::scale(double k) {
    double centerX = bottomLeftPoint_.getX() + getWidth() / 2.0;
    double centerY = bottomLeftPoint_.getY() + getHeight() / 2.0;

    double bottomLeftDeltaX = (bottomLeftPoint_.getX() - centerX) * k;
    double bottomLeftDeltaY = (bottomLeftPoint_.getY() - centerY) * k;
    bottomLeftPoint_.move(bottomLeftDeltaX, bottomLeftDeltaY);

    double topRightDeltaX = (topRightPoint_.getX() - centerX) * k;
    double topRightDeltaY = (topRightPoint_.getY() - centerY) * k;
    topRightPoint_.move(topRightDeltaX, topRightDeltaY);
}

double Rectangle::getWidth() const {
    return topRightPoint_.getX() - bottomLeftPoint_.getX();
}

double Rectangle::getHeight() const {
    return topRightPoint_.getY() - bottomLeftPoint_.getY();
}

std::ostream &operator<<(std::ostream &os, const Rectangle &rectangle) {
    FrameRectangle frameRect = rectangle.getFrameRectangle();
    Point topRightPoint = frameRect.getTopRightPoint();
    Point bottomLeftPoint = frameRect.getBottomLeftPoint();

    os << os.precision(2);
    os << rectangle.getName() << " ";
    os << bottomLeftPoint.getX() << " " << bottomLeftPoint.getY() << " ";
    os << topRightPoint.getX() << " " << topRightPoint.getY() << "\n";
    return os;
}


