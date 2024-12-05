//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYEIGHT_H
#define YEAR2024_DAYEIGHT_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayEight {
    public:
        std::vector<std::string> fileContents;

        explicit DayEight(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYEIGHT_H
