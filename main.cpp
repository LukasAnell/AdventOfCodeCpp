#include <iostream>

#include "Year2024/Day6/DaySix.h"

int main() {
    std::cout << "Day 6:" << std::endl;
    const Year2024::DaySix daySixSample("SampleInput.txt", true);
    std::cout << daySixSample.partOne() << std::endl;
    std::cout << daySixSample.partTwo() << std::endl;
    const Year2024::DaySix daySix("Input.txt", false);
    std::cout << daySix.partOne() << std::endl;
    std::cout << daySix.partTwo() << std::endl;
    std::cout << std::endl;

    return 0;
}
