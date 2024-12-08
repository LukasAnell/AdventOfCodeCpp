//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYSIX_H
#define YEAR2024_DAYSIX_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySix {
    public:
        std::vector<std::string> fileContents;

        explicit DaySix(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        static bool containsPosAndDir(const std::vector<std::pair<std::pair<int, int>, int>>& vector, const std::pair<std::pair<int, int>, int>& pair);
        static bool testLoop(const std::pair<int, int>& startPos, const std::vector<std::string>& map);
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYSIX_H
