cmake_minimum_required(VERSION 3.26)
project(advent1)

set(CMAKE_CXX_STANDARD 23)

add_executable(advent1 main.cpp
        adventDay1/day1.cpp
        adventDay1/day1.h
        adventDay1/day1Part2.cpp
        adventDay1/day1Part2.h
        adventDay2/day2.cpp
        adventDay2/day2.h
        adventDay2/day2Part2.cpp
        adventDay2/day2Part2.h
        adventDay3/day3.cpp
        adventDay3/day3.h
        adventDay3/day3Part2.cpp
        adventDay3/day3Part2.h
        adventDay5/day5.h
        adventDay5/day5.cpp
        adventDay5/day5Part2.cpp
        adventDay5/day5Part2.h
        adventDay5/mapRange.cpp
        adventDay5/mapRange.h)
