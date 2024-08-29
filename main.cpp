#include <iostream>
#include "Year2022/Day1/DayOne.h"
#include "Year2022/Day2/DayTwo.h"
#include "Year2022/Day3/DayThree.h"

int main() {
    std::cout << "Day 1:" << std::endl;
    const DayOne dayOneSample("sampleInput.txt");
    std::cout << dayOneSample.bothParts(1) << std::endl;
    std::cout << dayOneSample.bothParts(3) << std::endl;
    const DayOne dayOne("input.txt");
    std::cout << dayOne.bothParts(1) << std::endl;
    std::cout << dayOne.bothParts(3) << std::endl;
    std::cout << std::endl;

    std::cout << "Day 2:" << std::endl;
    const DayTwo dayTwoSample("sampleInput.txt");
    std::cout << dayTwoSample.partOne() << std::endl;
    std::cout << dayTwoSample.partTwo() << std::endl;
    const DayTwo dayTwo("input.txt");
    std::cout << dayTwo.partOne() << std::endl;
    std::cout << dayTwo.partTwo() << std::endl;
    std::cout << std::endl;

    std::cout << "Day 3:" << std::endl;
    const DayThree dayThreeSample("sampleInput.txt");
    std::cout << dayThreeSample.partOne() << std::endl;
    std::cout << dayThreeSample.partTwo() << std::endl;
    const DayThree dayThree("input.txt");
    std::cout << dayThree.partOne() << std::endl;
    std::cout << dayThree.partTwo() << std::endl;
    std::cout << std::endl;

    return 0;
}
