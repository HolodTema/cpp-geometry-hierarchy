#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x, double y) :
            x_(x),
            y_(y)
    { }

    double getX() const noexcept {
        return x_;
    }

    double getY() const noexcept {
        return y_;
    }

    void move(double deltaX, double deltaY) noexcept;

private:
    double x_;
    double y_;
};

#endif //POINT_H
