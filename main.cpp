#include <chrono>
#include <iostream>

#include "Year2024/Day1/DayOne.h"
#include "Year2024/Day2/DayTwo.h"
#include "Year2024/Day3/DayThree.h"
#include "Year2024/Day4/DayFour.h"
#include "Year2024/Day5/DayFive.h"
#include "Year2024/Day6/DaySix.h"
#include "Year2024/Day7/DaySeven.h"
#include "Year2024/Day8/DayEight.h"
#include "Year2024/Day9/DayNine.h"
#include "Year2024/Day10/DayTen.h"

int main() {
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    /*
    std::cout << "Day1:" << std::endl;
    const Year2024::DayOne dayOneSample("SampleInput.txt", true);
    // std::cout << dayOneSample.partOne() << std::endl;
    // std::cout << dayOneSample.partTwo() << std::endl;
    const Year2024::DayOne dayOne("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayOne.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayOne.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day2:" << std::endl;
    const Year2024::DayTwo dayTwoSample("SampleInput.txt", true);
    // std::cout << dayTwoSample.partOne() << std::endl;
    // std::cout << dayTwoSample.partTwo() << std::endl;
    const Year2024::DayTwo dayTwo("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayTwo.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayTwo.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day3:" << std::endl;
    const Year2024::DayThree dayThreeSample("SampleInput.txt", true);
    // std::cout << dayThreeSample.partOne() << std::endl;
    // std::cout << dayThreeSample.partTwo() << std::endl;
    const Year2024::DayThree dayThree("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayThree.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayThree.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day4:" << std::endl;
    const Year2024::DayFour dayFourSample("SampleInput.txt", true);
    // std::cout << dayFourSample.partOne() << std::endl;
    // std::cout << dayFourSample.partTwo() << std::endl;
    const Year2024::DayFour dayFour("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayFour.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayFour.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day5:" << std::endl;
    const Year2024::DayFive dayFiveSample("SampleInput.txt", true);
    // std::cout << dayFiveSample.partOne() << std::endl;
    // std::cout << dayFiveSample.partTwo() << std::endl;
    const Year2024::DayFive dayFive("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayFive.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayFive.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day6:" << std::endl;
    const Year2024::DaySix daySixSample("SampleInput.txt", true);
    // std::cout << daySixSample.partOne() << std::endl;
    // std::cout << daySixSample.partTwo() << std::endl;
    const Year2024::DaySix daySix("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << daySix.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << daySix.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day7:" << std::endl;
    const Year2024::DaySeven daySevenSample("SampleInput.txt", true);
    // std::cout << daySevenSample.partOne() << std::endl;
    // std::cout << daySevenSample.partTwo() << std::endl;
    const Year2024::DaySeven daySeven("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << daySeven.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << daySeven.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day8:" << std::endl;
    const Year2024::DayEight dayEightSample("SampleInput.txt", true);
    //std::cout << dayEightSample.partOne() << std::endl;
    //std::cout << dayEightSample.partTwo() << std::endl;
    const Year2024::DayEight dayEight("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayEight.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayEight.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;
*/

    std::cout << "Day9:" << std::endl;
    const Year2024::DayNine dayNineSample("SampleInput.txt", true);
    std::cout << dayNineSample.partOne() << std::endl;
    std::cout << dayNineSample.partTwo() << std::endl;
    const Year2024::DayNine dayNine("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayNine.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayNine.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;

/*
    std::cout << "Day10:" << std::endl;
    const Year2024::DayTen dayTenSample("SampleInput.txt", true);
    //std::cout << dayTenSample.partOne() << std::endl;
    //std::cout << dayTenSample.partTwo() << std::endl;
    const Year2024::DayTen dayTen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;
*/
    return 0;
}
