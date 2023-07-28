cmake_minimum_required(VERSION 3.19)
project(demo_tree)

set(CMAKE_CXX_STANDARD 11)

add_executable(demo_tree demo.cpp Node.h Node.cpp Tree.h Tree.cpp)