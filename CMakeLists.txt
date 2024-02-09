cmake_minimum_required(VERSION 3.27)
project(COMP345A1)

set(CMAKE_CXX_STANDARD 17)

add_executable(COMP345A1 src/main.cpp
        src/Character.h
        src/Fighter.h
        src/Character.cpp
        src/Fighter.cpp
)
