cmake_minimum_required(VERSION 3.14)
project(Threading_In_CPlusPlus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -pthread")

add_executable(matrix_multiplication_test matrix_multiplication_test.cpp)