//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYTWENTY_H
#define YEAR2024_DAYTWENTY_H
#include <string>
#include <unordered_set>
#include <vector>

namespace Year2024 {
    class DayTwenty {
    public:
        std::vector<std::string> fileContents;
        struct pairHash {
            template <class T1, class T2>
            std::size_t operator()(const std::pair<T1, T2>& pair) const {
                return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
            }
        };

        const std::unordered_set<std::pair<int, int>,pairHash> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        explicit DayTwenty(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTWENTY_H
