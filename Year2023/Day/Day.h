//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2023_DAY_H
#define YEAR2023_DAY_H
#include <string>
#include <vector>

namespace Year2023 {
    class Day {
        std::vector<std::string> fileContents;

        explicit Day(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
} // Year2023

#endif //YEAR2023_DAY_H
