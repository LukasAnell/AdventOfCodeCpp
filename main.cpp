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
#include "Year2024/Day11/DayEleven.h"
#include "Year2024/Day12/DayTwelve.h"
#include "Year2024/Day13/DayThirteen.h"
#include "Year2024/Day14/DayFourteen.h"
#include "Year2024/Day15/DayFifteen.h"
#include "Year2024/Day16/DaySixteen.h"
#include "Year2024/Day17/DaySeventeen.h"
#include "Year2024/Day18/DayEighteen.h"
#include "Year2024/Day19/DayNineteen.h"
#include "Year2024/Day20/DayTwenty.h"
#include "Year2024/Day21/DayTwentyOne.h"
#include "Year2024/Day23/DayTwentyThree.h"
#include "Year2024/Day24/DayTwentyFour.h"
#include "Year2024/Day25/DayTwentyFive.h"

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


    std::cout << "Day9:" << std::endl;
    const Year2024::DayNine dayNineSample("SampleInput.txt", true);
    //std::cout << dayNineSample.partOne() << std::endl;
    //std::cout << dayNineSample.partTwo() << std::endl;
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


    std::cout << "Day10:" << std::endl;
    const Year2024::DayTen dayTenSample("SampleInput.txt", true);
    std::cout << dayTenSample.partOne() << std::endl;
    std::cout << dayTenSample.partTwo() << std::endl;
    const Year2024::DayTen dayTen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayTen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayTen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day11:" << std::endl;
    const Year2024::DayEleven dayElevenSample("SampleInput.txt", true);
    //std::cout << dayElevenSample.partOne() << std::endl;
    //std::cout << dayElevenSample.partTwo() << std::endl;
    const Year2024::DayEleven dayEleven("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayEleven.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayEleven.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;
*/

    std::cout << "Day12:" << std::endl;
    const Year2024::DayTwelve dayTwelveSample("SampleInput.txt", true);
    //std::cout << dayTwelveSample.partOne() << std::endl;
    //std::cout << dayTwelveSample.partTwo() << std::endl;
    const Year2024::DayTwelve dayTwelve("Input.txt", false);

    start = std::chrono::steady_clock::now();
    std::cout << dayTwelve.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    std::cout << dayTwelve.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;

/*
    std::cout << "Day13:" << std::endl;
    const Year2024::DayThirteen dayThirteenSample("SampleInput.txt", true);
    //std::cout << dayThirteenSample.partOne() << std::endl;
    //std::cout << dayThirteenSample.partTwo() << std::endl;
    const Year2024::DayThirteen dayThirteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayThirteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayThirteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day14:" << std::endl;
    const Year2024::DayFourteen dayFourteenSample("SampleInput.txt", true);
    //std::cout << dayFourteenSample.partOne() << std::endl;
    //std::cout << dayFourteenSample.partTwo() << std::endl;
    const Year2024::DayFourteen dayFourteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayFourteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayFourteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day15:" << std::endl;
    const Year2024::DayFifteen dayFifteenSample("SampleInput.txt", true);
    //std::cout << dayFifteenSample.partOne() << std::endl;
    //std::cout << dayFifteenSample.partTwo() << std::endl;
    const Year2024::DayFifteen dayFifteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayFifteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayFifteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day16:" << std::endl;
    const Year2024::DaySixteen daySixteenSample("SampleInput.txt", true);
    //std::cout << daySixteenSample.partOne() << std::endl;
    //std::cout << daySixteenSample.partTwo() << std::endl;
    const Year2024::DaySixteen daySixteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << daySixteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << daySixteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day17:" << std::endl;
    const Year2024::DaySeventeen daySeventeenSample("SampleInput.txt", true);
    //std::cout << daySeventeenSample.partOne() << std::endl;
    //std::cout << daySeventeenSample.partTwo() << std::endl;
    const Year2024::DaySeventeen daySeventeen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << daySeventeen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << daySeventeen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day18:" << std::endl;
    const Year2024::DayEighteen dayEighteenSample("SampleInput.txt", true);
    //std::cout << dayEighteenSample.partOne() << std::endl;
    //std::cout << dayEighteenSample.partTwo() << std::endl;
    const Year2024::DayEighteen dayEighteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayEighteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayEighteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day19:" << std::endl;
    const Year2024::DayNineteen dayNineteenSample("SampleInput.txt", true);
    //std::cout << dayNineteenSample.partOne() << std::endl;
    //std::cout << dayNineteenSample.partTwo() << std::endl;
    const Year2024::DayNineteen dayNineteen("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayNineteen.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayNineteen.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day20:" << std::endl;
    const Year2024::DayTwenty dayTwentySample("SampleInput.txt", true);
    //std::cout << dayTwentySample.partOne() << std::endl;
    //std::cout << dayTwentySample.partTwo() << std::endl;
    const Year2024::DayTwenty dayTwenty("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwenty.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwenty.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day21:" << std::endl;
    const Year2024::DayTwentyOne dayTwentyOneSample("SampleInput.txt", true);
    //std::cout << dayTwentyOneSample.partOne() << std::endl;
    //std::cout << dayTwentyOneSample.partTwo() << std::endl;
    const Year2024::DayTwentyOne dayTwentyOne("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyOne.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyOne.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day22:" << std::endl;
    const Year2024::DayTwentyFive dayTwentyTwoSample("SampleInput.txt", true);
    //std::cout << dayTwentyTwoSample.partOne() << std::endl;
    //std::cout << dayTwentyTwoSample.partTwo() << std::endl;
    const Year2024::DayTwentyFive dayTwentyTwo("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyTwo.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyTwo.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day23:" << std::endl;
    const Year2024::DayTwentyThree dayTwentyThreeSample("SampleInput.txt", true);
    //std::cout << dayTwentyThreeSample.partOne() << std::endl;
    //std::cout << dayTwentyThreeSample.partTwo() << std::endl;
    const Year2024::DayTwentyThree dayTwentyThree("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyThree.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyThree.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day24:" << std::endl;
    const Year2024::DayTwentyFour dayTwentyFourSample("SampleInput.txt", true);
    //std::cout << dayTwentyFourSample.partOne() << std::endl;
    //std::cout << dayTwentyFourSample.partTwo() << std::endl;
    const Year2024::DayTwentyFour dayTwentyFour("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyFour.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyFour.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;


    std::cout << "Day25:" << std::endl;
    const Year2024::DayTwentyFive dayTwentyFiveSample("SampleInput.txt", true);
    //std::cout << dayTwentyFiveSample.partOne() << std::endl;
    //std::cout << dayTwentyFiveSample.partTwo() << std::endl;
    const Year2024::DayTwentyFive dayTwentyFive("Input.txt", false);

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyFive.partOne() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    start = std::chrono::steady_clock::now();
    //std::cout << dayTwentyFive.partTwo() << " | ";
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    std::cout << std::endl;
*/

    return 0;
}
