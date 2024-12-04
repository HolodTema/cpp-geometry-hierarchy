#ifndef RECTTRAPEZIUM_H
#define RECTTRAPEZIUM_H

#include "Shape.h"
#include "geometryExceptions.h"

class RectTrapezium : public Shape {
public:
    RectTrapezium(double bottomLeftX, double bottomLeftY, double bottomBase, double topBase, double height) :
        bottomLeftPoint_(Point(bottomLeftX, bottomLeftY)),
        bottomBase_(bottomBase),
        topBase_(topBase),
        height_(height)
    {
        if (bottomBase_ <= 0 || topBase_ <= 0 || height_ <= 0) {
            throw InvalidTrapeziumException();
        }
    }

    std::string getName() const override;

    double getArea() const noexcept override;

    FrameRectangle getFrameRectangle() const override;

    void move(const Point &point) override;

    void move(double deltaX, double deltaY) override;

    void scale(double k) override;

    Shape *clone() const override;

private:
    Point bottomLeftPoint_;
    double bottomBase_;
    double topBase_;
    double height_;
};


#endif //RECTTRAPEZIUM_H
