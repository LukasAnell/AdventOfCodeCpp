//
// Created by Lukas on 12/9/2024.
//

#include "DayTwelve.h"

#include "../../Utils/utils.h"
#include <algorithm>
#include <ranges>
#include <set>
#include <string>
#include <unordered_map>

namespace Year2024 {
    DayTwelve::DayTwelve(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 12, isSample);
    }

    void DayTwelve::dfs1(int r, int c, const char currentChar, std::set<std::pair<int, int> > &visited, int &area, int &sides) const {
        const int rows = static_cast<int>(fileContents.size());
        const int cols = static_cast<int>(fileContents[0].size());
        const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visited.emplace(r, c);
        area++;

        for (const auto& [dr, dc] : directions) {
            int newRow = r + dr;
            int newCol = c + dc;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || fileContents[newRow][newCol] != currentChar) {
                sides++;
            } else if (!visited.contains({newRow, newCol})) {
                dfs1(newRow, newCol, currentChar, visited, area, sides);
            }
        }
    }


    int DayTwelve::partOne() const {
        std::unordered_map<std::string, int> totalPrice;
        std::set<std::pair<int, int>> visited;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                const char currentChar = fileContents[r][c];
                if (!visited.contains({r, c})) {
                    int area = 0;
                    int perimeter = 0;
                    dfs1(r, c, currentChar, visited, area, perimeter);
                    totalPrice[std::string{currentChar}] += area * perimeter;
                }
            }
        }

        int sum = 0;
        for (const auto& price : totalPrice | std::ranges::views::values) {
            sum += price;
        }
        return sum;
    }

    void DayTwelve::dfs2(int r, int c, const char currentChar, std::set<std::pair<int, int>>& visited, std::set<std::pair<int, int>>& region) const {
        const int rows = static_cast<int>(fileContents.size());
        const int cols = static_cast<int>(fileContents[0].size());
        const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visited.emplace(r, c);
        region.emplace(r, c);

        for (const auto& [dr, dc] : directions) {
            const int newRow = r + dr;
            const int newCol = c + dc;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && fileContents[newRow][newCol] == currentChar && !visited.contains({newRow, newCol})) {
                dfs2(newRow, newCol, currentChar, visited, region);
            }
        }
    }

    int DayTwelve::findEdges(const std::set<std::pair<int, int>>& area) {
        int edges = 0;

        const int min_i = std::ranges::min_element(area,
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            }) -> first;
        const int max_i = std::ranges::max_element(area,
            [](const auto& a, const auto& b) {
                return a.first < b.first;
            }) -> first;
        const int min_j = std::ranges::min_element(area,
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }) -> second;
        const int max_j = std::ranges::max_element(area,
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }) -> second;

        for (int i = min_i; i <= max_i; ++i) {
            bool top_was_edge = false;
            bool bottom_was_edge = false;
            for (int j = min_j; j <= max_j; ++j) {
                const bool top_is_edge = area.contains({i, j}) && !area.contains({i - 1, j});
                const bool bottom_is_edge = area.contains({i, j}) && !area.contains({i + 1, j});

                if (top_is_edge && !top_was_edge) {
                    edges++;
                }
                if (bottom_is_edge && !bottom_was_edge) {
                    edges++;
                }

                top_was_edge = top_is_edge;
                bottom_was_edge = bottom_is_edge;
            }
        }

        for (int j = min_j; j <= max_j; ++j) {
            bool left_was_edge = false;
            bool right_was_edge = false;
            for (int i = min_i; i <= max_i; ++i) {
                const bool left_is_edge = area.contains({i, j}) && !area.contains({i, j - 1});
                const bool right_is_edge = area.contains({i, j}) && !area.contains({i, j + 1});

                if (left_is_edge && !left_was_edge) {
                    edges++;
                }
                if (right_is_edge && !right_was_edge) {
                    edges++;
                }

                left_was_edge = left_is_edge;
                right_was_edge = right_is_edge;
            }
        }

        return edges;
    }

    int DayTwelve::partTwo() const {
        std::unordered_map<std::string, int> totalPrice;
        std::set<std::pair<int, int>> visited;

        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                const char currentChar = fileContents[r][c];
                if (!visited.contains({r, c})) {
                    std::set<std::pair<int, int>> region;
                    dfs2(r, c, currentChar, visited, region);
                    const int area = static_cast<int>(region.size());
                    const int sides = findEdges(region);
                    totalPrice[std::string{currentChar}] += area * sides;
                }
            }
        }

        int sum = 0;
        for (const auto& price : totalPrice | std::ranges::views::values) {
            sum += price;
        }
        return sum;
    }
} // Year2024