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
        [[nodiscard]] static bool incrOrDecr(const std::vector<int>& vector);
        [[nodiscard]] static bool withinRange(const std::vector<int>& vector);
        [[nodiscard]] static std::vector<int> getRowVector(const std::string& row);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYTWO_H
