//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYTHIRTEEN_H
#define YEAR2024_DAYTHIRTEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayThirteen {
    public:
        std::vector<std::string> fileContents;

        explicit DayThirteen(const std::string& fileName, bool isSample);
        static int constructNum1(const std::string &line, int index);
        [[nodiscard]] int partOne() const;
        static long long constructNum2(const std::string &line, int index);
        static long long findMinTokens(long long aX, long long aY, long long bX, long long bY, long long pX, long long pY, int aCount, int bCount);
        [[nodiscard]] long long partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTHIRTEEN_H
