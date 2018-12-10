cmake_minimum_required(VERSION 3.12)
project(assignment5)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -g -ggdb)

include_directories("/usr/local/Cellar/freeglut/3.0.0/include")
link_directories("/usr/local/Cellar/freeglut/3.0.0/lib")
link_libraries("/usr/local/Cellar/freeglut/3.0.0/lib/libglut.dylib")
link_libraries("/opt/x11/lib/libGL.dylib")
add_executable(assignment5 Draw.cpp FigureManager.cpp BlackBoard.cpp)


