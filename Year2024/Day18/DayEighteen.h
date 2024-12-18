//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYEIGHTEEN_H
#define YEAR2024_DAYEIGHTEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayEighteen {
    public:
        std::vector<std::string> fileContents;
        const std::vector<std::pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        struct pairHash {
            template <class T1, class T2>
            std::size_t operator()(const std::pair<T1, T2>& pair) const {
                return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
            }
        };

        struct Node {
            std::pair<int, int> position;
            int g;
            int f;

            Node(const std::pair<int, int>& pos, const int gCost, const int fCost) : position(pos), g(gCost), f(fCost) {}

            bool operator<(const Node& other) const {
                return f > other.f;
            }
        };

        struct CompareNode {
            bool operator()(const Node& a, const Node& b) const {
                return a.f > b.f;
            }
        };

        explicit DayEighteen(const std::string& fileName, bool isSample);
        [[nodiscard]] static bool isValid(const std::pair<int, int>& position, const std::vector<std::vector<char>>& grid);
        [[nodiscard]] static int heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b);
        [[nodiscard]] int aStarPathfinding(const std::vector<std::vector<char>>& grid, std::pair<int, int> start, const std::pair<int, int> &goal) const;
        [[nodiscard]] int partOne(int size, int numBytes) const;
        [[nodiscard]] std::string partTwo(int size) const;
    };
} // Year2024

#endif //YEAR2024_DAYEIGHTEEN_H
