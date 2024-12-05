#include <iostream>
#include "Year2024/Day3/DayThree.h"

int main() {
    std::cout << "Day 3:" << std::endl;
    const Year2024::DayThree dayThreeSample("sampleInput.txt");
    std::cout << dayThreeSample.partOne() << std::endl;
    // std::cout << dayThreeSample.partTwo() << std::endl;
    const Year2024::DayThree dayThree("input.txt");
    std::cout << dayThree.partOne() << std::endl;
    // std::cout << dayThree.partTwo() << std::endl;
    std::cout << std::endl;


    return 0;
}
