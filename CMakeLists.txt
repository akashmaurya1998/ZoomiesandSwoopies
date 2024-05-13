cmake_minimum_required(VERSION 3.28)
project(Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project2 main.cpp
        Zoomie.cpp
        Organism.cpp
        Organism.h
        Swoopie.cpp
        World.cpp
        Zoomie.h
        Swoopie.h
        World.h
)
