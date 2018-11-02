cmake_minimum_required(VERSION 3.12)
project(CPPLAB)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/Cellar/log4cpp/1.1.3/include)
link_directories(/usr/local/Cellar/log4cpp/1.1.3/lib)

add_executable(CPPLAB main.cpp owner.cpp owner.h member.cpp member.h)