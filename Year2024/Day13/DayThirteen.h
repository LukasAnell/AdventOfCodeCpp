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
        static long long constructNum(const std::string &line, int index);
        [[nodiscard]] std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> constructPrizesVec(long long added) const;
        [[nodiscard]] static long long getTokens(std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> prizesVec);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] long long partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTHIRTEEN_H
