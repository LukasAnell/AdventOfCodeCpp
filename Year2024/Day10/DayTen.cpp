//
// Created by Lukas on 12/5/2024.
//

#include "DayTen.h"

#include "../../Utils/utils.h"
#include <string>
#include <unordered_set>

namespace Year2024 {
    DayTen::DayTen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 10, isSample);
    }

    bool DayTen::isValidMove(
        const int row,
        const int col,
        const std::vector<std::vector<int>>& map,
        const int prevHeight,
        const std::vector<std::vector<bool>>& visited,
        const bool partOne
    ) {
        const bool isWithinBounds = row >= 0 && row < map.size() && col >= 0 && col < map[0].size();
        const bool increasesByOne = map[row][col] == prevHeight + 1;
        if (partOne) {
            return isWithinBounds && increasesByOne && !visited[row][col];
        }
        return isWithinBounds && increasesByOne;
    }

    void DayTen::exploreTrail(
        int row,
        int col,
        const std::vector<std::vector<int>>& map,
        std::vector<std::vector<bool>>& visited,
        std::unordered_set<std::pair<int, int>,
        pairHash>& uniqueNines,
        int& score,
        const bool partOne
    ) {
        if (map[row][col] == 9) {
            if (partOne) {
                uniqueNines.emplace(row, col);
            } else {
                score += 1;
            }
            return;
        }

        visited[row][col] = true;
        const int currentHeight = map[row][col];

        if (isValidMove(row - 1, col, map, currentHeight, visited, partOne)) {
            exploreTrail(row - 1, col, map, visited, uniqueNines, score, partOne);
        }
        if (isValidMove(row + 1, col, map, currentHeight, visited, partOne)) {
            exploreTrail(row + 1, col, map, visited, uniqueNines, score, partOne);
        }
        if (isValidMove(row, col - 1, map, currentHeight, visited, partOne)) {
            exploreTrail(row, col - 1, map, visited, uniqueNines, score, partOne);
        }
        if (isValidMove(row, col + 1, map, currentHeight, visited, partOne)) {
            exploreTrail(row, col + 1, map, visited, uniqueNines, score, partOne);
        }

        visited[row][col] = false;
    }

    int DayTen::partOne() const {
        std::vector<std::vector<int>> topographicMap;
        std::vector<std::pair<int, int>> trailheadLocs;
        for (const auto& line : fileContents) {
            std::vector<int> intLine;
            for (const char ch : line) {
                int height = ch - '0';
                intLine.push_back(height);
                if (height == 0) {
                    trailheadLocs.emplace_back(topographicMap.size(), intLine.size() - 1);
                }
            }
            topographicMap.push_back(intLine);
        }

        int totalScore = 0;
        for (const auto& [row, col] : trailheadLocs) {
            std::vector visited(topographicMap.size(), std::vector(topographicMap[0].size(), false));
            std::unordered_set<std::pair<int, int>, pairHash> uniqueNines;
            int score = 0;
            exploreTrail(row, col, topographicMap, visited, uniqueNines, score, true);
            totalScore += static_cast<int>(uniqueNines.size());
        }

        return totalScore;
    }

    int DayTen::partTwo() const {
        std::vector<std::vector<int>> topographicMap;
        std::vector<std::pair<int, int>> trailheadLocs;
        for (const auto& line : fileContents) {
            std::vector<int> intLine;
            for (const char ch : line) {
                int height = ch - '0';
                intLine.push_back(height);
                if (height == 0) {
                    trailheadLocs.emplace_back(topographicMap.size(), intLine.size() - 1);
                }
            }
            topographicMap.push_back(intLine);
        }

        int totalScore = 0;
        for (const auto& [row, col] : trailheadLocs) {
            std::vector visited(topographicMap.size(), std::vector(topographicMap[0].size(), false));
            std::unordered_set<std::pair<int, int>, pairHash> uniqueNines;
            int score = 0;
            exploreTrail(row, col, topographicMap, visited, uniqueNines, score, false);
            totalScore += score;
        }

        return totalScore;
    }

}
