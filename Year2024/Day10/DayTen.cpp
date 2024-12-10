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

    struct DayTen::pairHash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    bool DayTen::isValidMoveP1(const int row, const int col, const std::vector<std::vector<int>>& map, const int prevHeight, const std::vector<std::vector<bool>>& visited) {
        return row >= 0 && row < map.size() && col >= 0 && col < map[0].size() && map[row][col] == prevHeight + 1 && !visited[row][col];
    }

    void DayTen::exploreTrailP1(int row, int col, const std::vector<std::vector<int>>& map, std::vector<std::vector<bool>>& visited, std::unordered_set<std::pair<int, int>, pairHash>& uniqueNines) {
        if (map[row][col] == 9) {
            uniqueNines.emplace(row, col);
            return;
        }

        visited[row][col] = true;
        const int currentHeight = map[row][col];

        if (isValidMoveP1(row - 1, col, map, currentHeight, visited)) {
            exploreTrailP1(row - 1, col, map, visited, uniqueNines);
        }
        if (isValidMoveP1(row + 1, col, map, currentHeight, visited)) {
            exploreTrailP1(row + 1, col, map, visited, uniqueNines);
        }
        if (isValidMoveP1(row, col - 1, map, currentHeight, visited)) {
            exploreTrailP1(row, col - 1, map, visited, uniqueNines);
        }
        if (isValidMoveP1(row, col + 1, map, currentHeight, visited)) {
            exploreTrailP1(row, col + 1, map, visited, uniqueNines);
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
            exploreTrailP1(row, col, topographicMap, visited, uniqueNines);
            totalScore += static_cast<int>(uniqueNines.size());
        }

        return totalScore;
    }

    bool DayTen::isValidMoveP2(const int row, const int col, const std::vector<std::vector<int>>& map, const int prevHeight) {
        return row >= 0 && row < map.size() && col >= 0 && col < map[0].size() && map[row][col] == prevHeight + 1;
    }

    int DayTen::exploreTrailP2(const int row, const int col, const std::vector<std::vector<int>>& map) {
        if (map[row][col] == 9) {
            return 1;
        }

        int score = 0;
        const int currentHeight = map[row][col];

        if (isValidMoveP2(row - 1, col, map, currentHeight)) {
            score += exploreTrailP2(row - 1, col, map);
        }
        if (isValidMoveP2(row + 1, col, map, currentHeight)) {
            score += exploreTrailP2(row + 1, col, map);
        }
        if (isValidMoveP2(row, col - 1, map, currentHeight)) {
            score += exploreTrailP2(row, col - 1, map);
        }
        if (isValidMoveP2(row, col + 1, map, currentHeight)) {
            score += exploreTrailP2(row, col + 1, map);
        }

        return score;
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
            totalScore += exploreTrailP2(row, col, topographicMap);
        }

        return totalScore;
    }

}
