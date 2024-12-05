//
// Created by Lukas on 8/28/2024.
//

#ifndef YEAR2022_DAYTWO_H
#define YEAR2022_DAYTWO_H
#include <string>
#include <vector>

namespace Year2022 {
    class DayTwo {
    public:
        std::vector<std::string> fileContents;

        explicit DayTwo(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2022_DAYTWO_H
