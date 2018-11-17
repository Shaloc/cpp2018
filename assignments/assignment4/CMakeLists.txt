cmake_minimum_required(VERSION 3.12)
project(assignment4)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -g -ggdb)

add_executable(assignment4 main.cpp List.cpp)
