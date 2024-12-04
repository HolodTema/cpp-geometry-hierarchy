#include "FrameRectangle.h"

Point FrameRectangle::getBottomLeftPoint() const noexcept {
    double x = pos_.getX() - width_ / 2.0;
    double y = pos_.getY() - height_ / 2.0;
    return Point(x, y);
}

Point FrameRectangle::getTopRightPoint() const noexcept {
    double x = pos_.getX() + width_ / 2.0;
    double y = pos_.getY() + height_ / 2.0;
    return Point(x, y);
}