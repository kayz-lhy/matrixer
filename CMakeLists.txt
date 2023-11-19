CMAKE_MINIMUM_REQUIRED(VERSION 3.26)


project(matrix)

include_directories(include)

add_executable(matrix
        src/main.cpp
        src/matrix.cpp
        include/matrix.hpp
        )