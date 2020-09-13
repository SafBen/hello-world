cmake_minimum_required(VERSION 3.15)
project(tables)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(tables
        main.c
        Makefile
        table-liste.c
        table-tableau.c
        table.h)
