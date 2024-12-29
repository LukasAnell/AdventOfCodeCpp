//
// Created by Lukas on 12/9/2024.
//

#include "DayTwenty.h"

#include "../../Utils/utils.h"
#include <queue>
#include <string>
#include <unordered_set>

namespace Year2024 {
    DayTwenty::DayTwenty(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 20, isSample);
    }

    int DayTwenty::partOne() const {
        const std::vector<std::string> grid = fileContents;
        std::pair<int, int> startPos;
        const int rows = grid.size();
        const int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 'S') {
                    startPos = {r, c};
                    break;
                }
            }
        }

        auto distances = std::vector(grid.size(), std::vector(grid[0].size(), -1));
        distances[startPos.first][startPos.second] = 0;

        int r = startPos.first;
        int c = startPos.second;
        while (grid[r][c] != 'E') {
            for (const auto&[row, col] : directions) {
                const int newR = r + row;
                const int newC = c + col;
                if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size()) {
                    continue;
                }
                if (grid[newR][newC] == '#') {
                    continue;
                }
                if (distances[newR][newC] != -1) {
                    continue;
                }
                distances[newR][newC] = distances[r][c] + 1;
                r = newR;
                c = newC;
            }
        }

        int count = 0;
        for (int i = 0; i < distances.size(); i++) {
            for (int j = 0; j < distances[i].size(); j++) {
                if (grid[i][j] == '#') {
                    continue;
                }
                std::vector<std::pair<int, int>> newDirections = {{i + 2, j}, {i + 1, j + 1}, {i, j + 2}, {i - 1, j + 1}};
                for (auto&[row, col] : newDirections) {
                    const int newR = row;
                    const int newC = col;
                    if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size()) {
                        continue;
                    }
                    if (grid[newR][newC] == '#') {
                        continue;
                    }
                    if (abs(distances[i][j] - distances[newR][newC]) >= 102) {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int DayTwenty::partTwo() const {
        const std::vector<std::string> grid = fileContents;
        std::pair<int, int> startPos;
        const int rows = grid.size();
        const int cols = grid[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 'S') {
                    startPos = {r, c};
                    break;
                }
            }
        }

        auto distances = std::vector(grid.size(), std::vector(grid[0].size(), -1));
        distances[startPos.first][startPos.second] = 0;

        int r = startPos.first;
        int c = startPos.second;
        while (grid[r][c] != 'E') {
            for (const auto&[row, col] : directions) {
                const int newR = r + row;
                const int newC = c + col;
                if (newR < 0 || newC < 0 || newR >= grid.size() || newC >= grid[0].size()) {
                    continue;
                }
                if (grid[newR][newC] == '#') {
                    continue;
                }
                if (distances[newR][newC] != -1) {
                    continue;
                }
                distances[newR][newC] = distances[r][c] + 1;
                r = newR;
                c = newC;
            }
        }

        int count = 0;
        for (r = 0; r < rows; r++) {
            for (c = 0; c < cols; c++) {
                if (grid[r][c] == '#') {
                    continue;
                }
                for (int radius = 2; radius < 21; radius++) {
                    for (int dr = 0; dr <= radius; dr++) {
                        const int dc = radius - dr;
                        const std::unordered_set<std::pair<int, int>, pairHash> newDirections = {
                            {r + dr, c + dc}, {r + dr, c - dc}, {r - dr, c + dc}, {r - dr, c - dc}
                        };
                        for (const auto&[nr, nc] : newDirections) {
                            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                                continue;
                            }
                            if (grid[nr][nc] == '#') {
                                continue;
                            }
                            if (distances[r][c] - distances[nr][nc] >= 100 + radius) {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
} // Year2024