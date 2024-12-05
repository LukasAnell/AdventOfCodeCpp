//
// Created by Lukas on 12/3/2024.
//

#ifndef YEAR2024_DAYTWO_H
#define YEAR2024_DAYTWO_H
#include <string>
#include <vector>


namespace Year2024 {
    class DayTwo {
    public:
        std::vector<std::string> fileContents;

        explicit DayTwo(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] static bool incrOrDecr(const std::vector<int>& vector);
        [[nodiscard]] static bool withinRange(const std::vector<int>& vector);
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYTWO_H
