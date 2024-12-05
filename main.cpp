#include <iostream>

#include "Year2024/Day5/DayFive.h"

int main() {
    std::cout << "Day 5:" << std::endl;
    const Year2024::DayFive dayFiveSample("sampleInput.txt");
    std::cout << dayFiveSample.partOne() << std::endl;
    std::cout << dayFiveSample.partTwo() << std::endl;
    const Year2024::DayFive dayFive("input.txt");
    std::cout << dayFive.partOne() << std::endl;
    std::cout << dayFive.partTwo() << std::endl;
    std::cout << std::endl;

    return 0;
}
