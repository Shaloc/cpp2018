cmake_minimum_required(VERSION 3.12)
project(CPPHomework3)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall)

add_executable(assignment3 main.cpp Matrix.cpp Vector.cpp)