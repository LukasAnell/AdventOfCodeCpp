#include <iostream>

#include "Year2024/Day7/DaySeven.h"

int main() {
    std::cout << "Day 7:" << std::endl;
    const Year2024::DaySeven daySevenSample("SampleInput.txt", true);
    std::cout << daySevenSample.partOne() << std::endl;
    //std::cout << daySevenSample.partTwo() << std::endl;
    const Year2024::DaySeven daySeven("Input.txt", false);
    std::cout << daySeven.partOne() << std::endl;
    //std::cout << daySeven.partTwo() << std::endl;
    std::cout << std::endl;

    return 0;
}
