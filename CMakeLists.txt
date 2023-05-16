cmake_minimum_required(VERSION 3.24)
project(cpu_process_scheduling_algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpu_process_scheduling_algorithms
        main.cpp Process.h scheduling_algorithms.h scheduling_algorithms.cpp)
