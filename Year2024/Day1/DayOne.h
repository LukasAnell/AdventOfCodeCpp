//
// Created by Lukas on 12/3/2024.
//

#ifndef YEAR2024_DAYONE_H
#define YEAR2024_DAYONE_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayOne {
    public:
        std::vector<std::string> fileContents;

        explicit DayOne(const std::string& fileName, bool isSample);
        [[nodiscard]] static std::pair<int, int> constructNums(const std::string& input);
        [[nodiscard]] std::pair<std::vector<int>, std::vector<int>> constructCols() const;
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYONE_H
