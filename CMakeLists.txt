cmake_minimum_required(VERSION 3.15)
project(advent_of_code_2019)

set(CMAKE_CXX_STANDARD 14)

add_executable(advent_of_code_2019 day01/main.cpp day02/main.cpp day02/IntcodeInterpreter.cpp day02/IntcodeInterpreter.h day03/main.cpp day04/main.cpp day06/main.cpp day08/main.cpp)