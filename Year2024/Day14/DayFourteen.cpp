//
// Created by Lukas on 12/9/2024.
//

#include "DayFourteen.h"

#include <algorithm>
#include <iostream>

#include "../../Utils/utils.h"
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>

namespace Year2024 {
    DayFourteen::DayFourteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 14, isSample);
    }

    int DayFourteen::constructNum(const std::string &line, const int index) {
        std::string out = "";
        for (int i = index; i < line.size(); i++) {
            if (line[i] == ',') {
                break;
            }
            out += line[i];
        }
        return std::stoi(out);
    }

    int DayFourteen::partOne(const int height, const int width) const {
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> robots;
        for (std::string line : fileContents) {
            std::string positionStr = line.substr(2, line.find(" v="));
            std::string velocityStr = line.substr(line.find(" v=") + 3);
            std::pair position = {stoi(positionStr.substr(0, positionStr.find(","))), stoi(positionStr.substr(positionStr.find(",") + 1))};
            std::pair velocity = {stoi(velocityStr.substr(0, velocityStr.find(","))), stoi(velocityStr.substr(velocityStr.find(",") + 1))};
            robots.emplace_back(std::pair(position, velocity));
        }

        for (int i = 0; i < 100; i++) {
            for (auto& robot : robots) {
                robot.first.first = (robot.first.first + robot.second.first + width) % width;
                robot.first.second = (robot.first.second + robot.second.second + height) % height;
            }
        }

        int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        for (const auto& robot : robots) {
            const int x = robot.first.first;
            const int y = robot.first.second;
            if (x == width / 2 || y == height / 2) continue;
            if (x < width / 2 && y < height / 2) ++q1;
            else if (x >= width / 2 && y < height / 2) ++q2;
            else if (x < width / 2 && y >= height / 2) ++q3;
            else if (x >= width / 2 && y >= height / 2) ++q4;
        }

        int safetyFactor = q1 * q2 * q3 * q4;
        return safetyFactor;
    }

    std::vector<std::pair<int, int>> DayFourteen::fourNeighborCoords(int x, int y, const int width, const int height) {
        return {
                {(x + 1) % width, y},
                {(x - 1 + width) % width, y},
                {x, (y + 1) % height},
                {x, (y - 1 + height) % height}
        };
    }

    int DayFourteen::partTwo(const int height, const int width) const {
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> robots;
        for (const std::string& line : fileContents) {
            std::string positionStr = line.substr(2, line.find(" v="));
            std::string velocityStr = line.substr(line.find(" v=") + 3);
            std::pair position = {stoi(positionStr.substr(0, positionStr.find(","))), stoi(positionStr.substr(positionStr.find(",") + 1))};
            std::pair velocity = {stoi(velocityStr.substr(0, velocityStr.find(","))), stoi(velocityStr.substr(velocityStr.find(",") + 1))};
            robots.emplace_back(std::pair(position, velocity));
        }

        std::unordered_map<int, int> heuristic;

        for (int t = 0; t <= height * width; t++) {
            std::unordered_set<std::pair<int, int>, pairHash> sparse;
            for (const auto& robot : robots) {
                int x = (robot.first.first + robot.second.first * t + width) % width;
                int y = (robot.first.second + robot.second.second * t + height) % height;
                sparse.insert({x, y});
            }

            for (const auto& [x, y] : sparse) {
                for (const auto& [nx, ny] : fourNeighborCoords(x, y, width, height)) {
                    if (sparse.contains({nx, ny})) {
                        heuristic[t]++;
                    }
                }
            }
        }

        const int bestTime = std::ranges::max_element(heuristic,
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            }) -> first;

        return bestTime;
    }
} // Year2024