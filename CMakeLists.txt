cmake_minimum_required(VERSION 3.5.1)
project(graphEvaluation)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Graph.hpp Graph.cpp AtomicGraph.cpp AtomicGraph.hpp GraphMutex.hpp GraphMutex.cpp)
add_executable(graphEvaluation ${SOURCE_FILES})