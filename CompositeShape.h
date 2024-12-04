#ifndef COMPOSITE_SHAPE_H
#define COMPOSITE_SHAPE_H

#include "Shape.h"

class CompositeShape {
public:
    CompositeShape(unsigned int len):
        len_(len){

    }

    unsigned int getLen() const noexcept {
        return len_;
    }
private:
    unsigned int len_;
    Shape* array;
};

#endif //COMPOSITE_SHAPE_H
