//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYSIXTEEN_H
#define YEAR2024_DAYSIXTEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySixteen {
    public:
        std::vector<std::string> fileContents;
        struct TupleHash {
            template <class T1, class T2, class T3>
            std::size_t operator()(const std::tuple<T1, T2, T3>& t) const {
                auto h1 = std::hash<T1>{}(std::get<0>(t));
                auto h2 = std::hash<T2>{}(std::get<1>(t));
                auto h3 = std::hash<T3>{}(std::get<2>(t));
                return h1 ^ h2 ^ h3;
            }
        };

        struct pairHash {
            template <class T1, class T2>
            std::size_t operator() (const std::pair<T1, T2>& pair) const {
                return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
            }
        };

        struct Reindeer {
            int x;
            int y;
            int facing; // 0 = up, 1 = right, 2 = down, 3 = left
        };

        struct End {
            int x;
            int y;
        };

        struct State {
            int x, y, facing, score;
            std::vector<std::pair<int, int>> path;
            bool operator>(const State& other) const {
                return score > other.score;
            }
        };

        explicit DaySixteen(const std::string& fileName, bool isSample);
        static void move(const std::vector<std::vector<char>>& maze, Reindeer& rein, int direction);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYSIXTEEN_H
