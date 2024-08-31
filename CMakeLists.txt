cmake_minimum_required(VERSION 3.29)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdventOfCode main.cpp
        Year2022/Day1/dayOne.cpp
        Year2022/Day1/dayOne.h
        utils.cpp
        utils.h
        Year2022/Day2/DayTwo.cpp
        Year2022/Day2/DayTwo.h
        Year2022/Day2/DayTwo.cpp
        Year2022/Day2/DayTwo.h
        Year2022/Day3/DayThree.cpp
        Year2022/Day3/DayThree.h
        Year2022/Day4/DayFour.cpp
        Year2022/Day4/DayFour.h
        Year2022/Day5/DayFive.cpp
        Year2022/Day5/DayFive.h
        Year2022/Day6/DaySix.cpp
        Year2022/Day6/DaySix.h
        Year2022/Day7/DaySeven.cpp
        Year2022/Day7/DaySeven.h)
