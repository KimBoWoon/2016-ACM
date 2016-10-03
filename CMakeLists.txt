cmake_minimum_required(VERSION 3.6)
project(2016_ACM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Prob-J/Prob-J.cpp)

add_executable(2016_ACM ${SOURCE_FILES})