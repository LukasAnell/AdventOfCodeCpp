//
// Created by Lukas on 12/5/2024.
//

#include "DaySix.h"

#include "../../Utils/utils.h"
#include <iostream>
#include <string>

namespace Year2024 {
    DaySix::DaySix(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 6, isSample);
    }

    int DaySix::partOne() const {
        std::vector<std::string> map = fileContents;

        std::pair<int, int> startingPosition;
        std::string direction;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                if (fileContents[r][c] == '^') {
                    startingPosition = {r, c};
                    direction = "UP";
                    break;
                }
            }
        }

        std::pair<int, int> position = startingPosition;
        while (true) {
            map[position.first][position.second] = 'X';
            if (direction == "UP") {
                if (position.first - 1 < 0) {
                    break;
                }
                if (map[position.first - 1][position.second] == '#') {
                    direction = "RIGHT";
                } else {
                    position = {position.first - 1, position.second};
                }
            }
            if (direction == "RIGHT") {
                if (position.second + 1 >= map[0].size()) {
                    break;
                }
                if (map[position.first][position.second + 1] == '#') {
                    direction = "DOWN";
                } else {
                    position = {position.first, position.second + 1};
                }
            }
            if (direction == "DOWN") {
                if (position.first + 1 >= map.size()) {
                    break;
                }
                if (map[position.first + 1][position.second] == '#') {
                    direction = "LEFT";
                } else {
                    position = {position.first + 1, position.second};
                }
            }
            if (direction == "LEFT") {
                if (position.second - 1 < 0) {
                    break;
                }
                if (map[position.first][position.second - 1] == '#') {
                    direction = "UP";
                } else {
                    position = {position.first, position.second - 1};
                }
            }
        }

        int count = 0;
        for (const std::string& line : map) {
            for (const char character : line) {
                if (character == 'X') {
                    count++;
                }
            }
        }
        return count;
    }

    bool DaySix::containsPosAndDir(const std::vector<std::pair<std::pair<int, int>, int>>& vector, const std::pair<std::pair<int, int>, int>& pair) {
        for (const auto& element : vector) {
            if (element == pair) {
                return true;
            }
        }
        return false;
    }

    bool DaySix::testLoop(const std::pair<int, int>& startPos, const std::vector<std::string>& map) {
        std::vector<std::pair<std::pair<int, int>, int>> turnPoints;
        std::string direction = "UP";
        int r = startPos.first;
        int c = startPos.second;
        while (true) {
            if (direction == "UP") {
                if (r == 0) {
                    break;
                }
                if (map[r - 1][c] != '#') {
                    r--;
                } else {
                    direction = "RIGHT";
                    if (containsPosAndDir(turnPoints, std::pair(std::pair(c, r), 0))) {
                        return true;
                    }
                    turnPoints.emplace_back(std::pair(c, r), 0);
                }
            }
            if (direction == "RIGHT") {
                if (c == map[0].size() - 1) {
                    break;
                }
                if (map[r][c + 1] != '#') {
                    c++;
                } else {
                    direction = "DOWN";
                    if (containsPosAndDir(turnPoints, std::pair(std::pair(c, r), 1))) {
                        return true;
                    }
                    turnPoints.emplace_back(std::pair(c, r), 1);
                }
            }
            if (direction == "DOWN") {
                if (r == map.size() - 1) {
                    break;
                }
                if (map[r + 1][c] != '#') {
                    r++;
                } else {
                    direction = "LEFT";
                    if (containsPosAndDir(turnPoints, std::pair(std::pair(c, r), 2))) {
                        return true;
                    }
                    turnPoints.emplace_back(std::pair(c, r), 2);
                }
            }
            if (direction == "LEFT") {
                if (c == 0) {
                    break;
                }
                if (map[r][c - 1] != '#') {
                    c--;
                } else {
                    direction = "UP";
                    if (containsPosAndDir(turnPoints, std::pair(std::pair(c, r), 3))) {
                        return true;
                    }
                    turnPoints.emplace_back(std::pair(c, r), 3);
                }
            }
        }
        return false;
    }

    int DaySix::partTwo() const {
        std::pair<int, int> position;
        int count = 0;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[r].size(); c++) {
                if (fileContents[r][c] == '^') {
                    position = {r, c};
                    break;
                }
            }
        }
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[r].size(); c++) {
                if (fileContents[r][c] != '#' && (r != position.first || c != position.second)) {
                    std::vector<std::string> temp;
                    for (const auto& fileContent : fileContents) {
                        temp.push_back(fileContent);
                    }
                    temp[r][c] = '#';
                    if (testLoop(position, temp)) {
                        count++;
                    }
                    temp[r][c] = '.';
                }
            }
        }
        return count;
    }
}
