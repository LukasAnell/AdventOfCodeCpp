//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYTWENTY_H
#define YEAR2024_DAYTWENTY_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayTwenty {
    public:
        std::vector<std::string> fileContents;
        struct State {
            int x, y, time, cheatUsed;
        };

        explicit DayTwenty(const std::string& fileName, bool isSample);
        static int bfs(const std::vector<std::string>& map, int startX, int startY, int endX, int endY);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTWENTY_H
