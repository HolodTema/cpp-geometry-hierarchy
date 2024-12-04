cmake_minimum_required(VERSION 3.25)
project(Geometry)

set(CMAKE_CXX_STANDARD 17)

add_executable(Geometry main.cpp Point.cpp Point.h Shape.h FrameRectangle.cpp FrameRectangle.h Rectangle.cpp Rectangle.h geometryExceptions.h RectTrapezium.cpp RectTrapezium.h CompositeShape.cpp CompositeShape.h)
