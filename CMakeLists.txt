cmake_minimum_required(VERSION 3.7)
project(graphEvaluation)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp Graph.hpp Graph.cpp AtomicGraph.cpp AtomicGraph.hpp GraphMutex.hpp GraphMutex.cpp GraphSharedMutex.hpp GraphSharedMutex.cpp)
add_executable(graphEvaluation ${SOURCE_FILES})

find_package(Threads)
target_link_libraries(graphEvaluation ${CMAKE_THREAD_LIBS_INIT})