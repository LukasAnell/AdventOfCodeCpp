//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYTEN_H
#define YEAR2024_DAYTEN_H
#include <string>
#include <unordered_set>
#include <vector>

namespace Year2024 {
    class DayTen {
    public:
        std::vector<std::string> fileContents;

        explicit DayTen(const std::string& fileName, bool isSample);
        struct pairHash;
        [[nodiscard]] static bool isValidMoveP1(int row, int col, const std::vector<std::vector<int>>& map, int prevHeight, const std::vector<std::vector<bool>>& visited);
        static void exploreTrailP1(int row, int col, const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& visited, std::unordered_set<std::pair<int, int>, pairHash>& uniqueNines);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] static bool isValidMoveP2(int row, int col, const std::vector<std::vector<int>>& map, int prevHeight);
        [[nodiscard]] static int exploreTrailP2(int row, int col, const std::vector<std::vector<int>>& map);
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYTEN_H
