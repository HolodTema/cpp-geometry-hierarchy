#ifndef GEOMETRY_EXCEPTIONS_H
#define GEOMETRY_GEOMETRYEXCEPTIONS_H

#include <stdexcept>

class NoMemoryToAllocateException: public std::exception {
public:
    const char * what() const noexcept override {
        return "Error: no dynamic memory to allocate left\n";
    }
};

class InvalidRectangleException: public std::exception {
public:
    const char * what() const noexcept override {
        return "Error: unable to create rectangle with given points\n";
    }
};

class InvalidTrapeziumException: public std::exception {
public:
    const char * what() const noexcept override {
        return "Error: unable to create trapezium with given bases, height and bottom left point\n";
    }
};

class InvalidFrameRectangleException: public std::exception {
public:
    const char * what() const noexcept override {
        return "Error: unable to create frameRectangle with given width and height\n";
    }
};
#endif GEOMETRY_EXCEPTIONS_H
