//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYTWELVE_H
#define YEAR2024_DAYTWELVE_H
#include <set>
#include <string>
#include <vector>

namespace Year2024 {
    struct LineSegment;

    class DayTwelve {
    public:
        std::vector<std::string> fileContents;

        explicit DayTwelve(const std::string& fileName, bool isSample);
        void dfs1(int r, int c, char currentChar, std::set<std::pair<int, int>>& visited, int& area, int& sides) const;
        [[nodiscard]] int partOne() const;
        void dfs2(int r, int c, char currentChar, std::set<std::pair<int, int>>& visited, std::set<std::pair<int, int>>& region) const;
        [[nodiscard]] static int findEdges(const std::set<std::pair<int, int>>& area);
        [[nodiscard]] int partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTWELVE_H
