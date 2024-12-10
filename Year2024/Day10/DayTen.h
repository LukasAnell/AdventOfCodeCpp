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
        struct pairHash {
            template <class T1, class T2>
            std::size_t operator() (const std::pair<T1, T2>& pair) const {
                return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
            }
        };
        [[nodiscard]] static bool isValidMove(
            int row,
            int col,
            const std::vector<std::vector<int>>& map,
            int prevHeight,
            const std::vector<std::vector<bool>>& visited,
            bool partOne
        );
        static void exploreTrail(
            int row,
            int col,
            const std::vector<std::vector<int>>& map,
            std::vector<std::vector<bool>>& visited,
            std::unordered_set<std::pair<int, int>,
            pairHash>& uniqueNines,
            int& score,
            bool partOne
        );
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYTEN_H
