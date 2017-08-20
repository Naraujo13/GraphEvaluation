cmake_minimum_required(VERSION 3.7)
project(graphEvaluation)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.hpp Graph.cpp)
add_executable(graphEvaluation ${SOURCE_FILES})