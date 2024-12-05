//
// Created by Lukas on 8/29/2024.
//

#ifndef YEAR2022_DAYFOUR_H
#define YEAR2022_DAYFOUR_H
#include <string>
#include <vector>

namespace Year2022 {
    class DayFour {
    public:
        std::vector<std::string> fileContents;

        explicit DayFour(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2022_DAYFOUR_H
