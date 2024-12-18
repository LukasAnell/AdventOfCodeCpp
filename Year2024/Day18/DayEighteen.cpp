//
// Created by Lukas on 12/9/2024.
//

#include "DayEighteen.h"

#include <iostream>
#include <queue>

#include "../../Utils/utils.h"
#include <string>
#include <unordered_set>

namespace Year2024 {
    DayEighteen::DayEighteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 18, isSample);
    }

    bool DayEighteen::isValid(const std::pair<int, int>& position, const std::vector<std::vector<char>>& grid) {
        return position.first >= 0 && position.first < grid.size()
        && position.second >= 0 && position.second < grid[0].size()
        && grid[position.first][position.second] != '#';
    }

    int DayEighteen::heuristic(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }

    int DayEighteen::aStarPathfinding(const std::vector<std::vector<char>>& grid, std::pair<int, int> start, const std::pair<int, int>& goal) const {
        std::priority_queue<Node, std::vector<Node>, CompareNode> openSet;
        std::unordered_set<std::pair<int, int>, pairHash> closedSet;
        openSet.emplace(start, 0, heuristic(start, goal));

        while (!openSet.empty()) {
            Node current = openSet.top();
            openSet.pop();

            if (current.position == goal) {
                return current.g;
            }

            closedSet.insert(current.position);
            for (const auto& direction : directions) {
                std::pair neighbor = {current.position.first + direction.first, current.position.second + direction.second};
                if (isValid(neighbor, grid) && !closedSet.contains(neighbor)) {
                    int tentativeG = current.g + 1;
                    openSet.emplace(neighbor, tentativeG, tentativeG + heuristic(neighbor, goal));
                }
            }
        }

        return -1;
    }

    int DayEighteen::partOne(const int size, const int numBytes) const {
        std::vector<std::pair<int, int>> byteFalls;
        for (std::string line : fileContents) {
            std::vector<std::string> split = utils::splitString(line, ",");
            byteFalls.emplace_back(stoi(split[0]), stoi(split[1]));
        }
        std::vector grid(size, std::vector(size, '.'));
        for (int i = 0; i < std::min(numBytes, static_cast<int>(byteFalls.size())); i++) {
            const auto& fall = byteFalls[i];
            if (fall.first >= 0 && fall.first < size && fall.second >= 0 && fall.second < size) {
                grid[fall.second][fall.first] = '#';
            }
        }

        return aStarPathfinding(grid, {0, 0}, {size - 1, size - 1});
    }

    std::string DayEighteen::partTwo(const int size) const {
        std::vector<std::pair<int, int>> byteFalls;
        for (const std::string& line : fileContents) {
            std::vector<std::string> split = utils::splitString(line, ",");
            byteFalls.emplace_back(stoi(split[0]), stoi(split[1]));
        }
        std::vector grid(size, std::vector(size, '.'));
        for (const auto& fall : byteFalls) {
            if (fall.first >= 0 && fall.first < size && fall.second >= 0 && fall.second < size) {
                grid[fall.second][fall.first] = '#';
            }
        }

        for (int i = byteFalls.size() - 1; i >= 0; i--) {
            const auto& fall = byteFalls[i];
            if (fall.first >= 0 && fall.first < size && fall.second >= 0 && fall.second < size) {
                grid[fall.second][fall.first] = '.';
            }
            if (aStarPathfinding(grid, {0, 0}, {size - 1, size - 1}) != -1) {
                return std::to_string(fall.first) + "," + std::to_string(fall.second);
            }
        }

        return "No Solution";
    }
} // Year2024