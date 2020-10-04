cmake_minimum_required(VERSION 3.17)
project(Train)

set(CMAKE_CXX_STANDARD 14)

add_executable(Train main.cpp Rectangle.cpp Rectangle.h Segment.cpp Segment.h)