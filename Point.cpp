#include "Point.h"

void Point::move(double deltaX, double deltaY) noexcept {
    x_ += deltaX;
    y_ += deltaY;
}