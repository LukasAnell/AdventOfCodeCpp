//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYFIVE_H
#define YEAR2024_DAYFIVE_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayFive {
    public:
        std::vector<std::string> fileContents;

        explicit DayFive(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
        [[nodiscard]] static bool customComparator(int a, int b, const std::vector<std::pair<int, int>>& rules);
    };
}

#endif //YEAR2024_DAYFIVE_H
