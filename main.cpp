#include <iostream>

#include "Year2024/Day2/DayTwo.h"
#include "Year2024/Day4/DayFour.h"

int main() {
    std::cout << "Day 4:" << std::endl;
    const Year2024::DayFour dayFourSample("sampleInput.txt");
    std::cout << dayFourSample.partOne() << std::endl;
    //std::cout << dayFourSample.partTwo() << std::endl;
    const Year2024::DayFour dayFour("input.txt");
    std::cout << dayFour.partOne() << std::endl;
    //std::cout << dayFour.partTwo() << std::endl;
    std::cout << std::endl;

    return 0;
}
