//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYFOURTEEN_H
#define YEAR2024_DAYFOURTEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayFourteen {
    public:
        std::vector<std::string> fileContents;

        struct pairHash {
            template <class T1, class T2>
            std::size_t operator() (const std::pair<T1, T2>& pair) const {
                return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
            }
        };

        explicit DayFourteen(const std::string& fileName, bool isSample);
        [[nodiscard]] static int constructNum(const std::string &line, int index);
        [[nodiscard]] int partOne(int height, int width) const;
        [[nodiscard]] static std::vector<std::pair<int, int>> fourNeighborCoords(int x, int y, int width, int height);
        [[nodiscard]] int partTwo(int height, int width) const;
    };
} // Year2024

#endif //YEAR2024_DAYFOURTEEN_H
