//
// Created by Lukas on 12/5/2024.
//

#include "DayEight.h"

#include "../../Utils/utils.h"
#include <map>
#include <ranges>
#include <set>
#include <string>

namespace Year2024 {
    DayEight::DayEight(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 8, isSample);
    }

    int DayEight::partOne() const {
        std::map<char, std::vector<std::pair<int, int>>> antennaMap;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                if (char key = fileContents[r][c]; key != '.') {
                    antennaMap[key].emplace_back(r, c);
                }
            }
        }

        std::set<std::pair<int, int>> antinodes;

        for (const auto& [key, positions] : antennaMap) {
            for (int i = 0; i < positions.size(); i++) {
                for (int j = 0; j < positions.size(); j++) {
                    if (i == j) {
                        continue;
                    }
                    auto [iFirst, iSecond] = positions[i];
                    auto [jFirst, jSecond] = positions[j];

                    const int yDiff = jFirst - iFirst;
                    const int xDiff = jSecond - iSecond;

                    for (int k = -1; k <= 1; k += 2) {
                        int antinodeY = iFirst + k * yDiff;
                        int antinodeX = iSecond + k * xDiff;

                        if (antinodeY >= 0 && antinodeY < fileContents.size() &&
                            antinodeX >= 0 && antinodeX < fileContents[0].size() &&
                            fileContents[antinodeY][antinodeX] != key) {
                            antinodes.emplace(antinodeY, antinodeX);
                            }
                    }
                }
            }
        }

        return static_cast<int>(antinodes.size());
    }

    int DayEight::partTwo() const {
        std::map<char, std::vector<std::pair<int, int>>> antennaMap;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                if (char key = fileContents[r][c]; key != '.') {
                    antennaMap[key].emplace_back(r, c);
                }
            }
        }

        std::set<std::pair<int, int>> antinodes;

        for (const auto& positions : antennaMap | std::ranges::views::values) {
            for (int i = 0; i < positions.size(); i++) {
                for (int j = 0; j < positions.size(); j++) {
                    if (i == j) {
                        continue;
                    }
                    auto [iFirst, iSecond] = positions[i];
                    auto [jFirst, jSecond] = positions[j];

                    const int yDiff = jFirst - iFirst;
                    const int xDiff = jSecond - iSecond;

                    for (int k = -1; k <= 1; k += 2) {
                        int antinodeY = iFirst + k * yDiff;
                        int antinodeX = iSecond + k * xDiff;

                        while (antinodeY >= 0 && antinodeY < fileContents.size() &&
                               antinodeX >= 0 && antinodeX < fileContents[0].size()) {
                            antinodes.emplace(antinodeY, antinodeX);
                            antinodeY += k * yDiff;
                            antinodeX += k * xDiff;
                               }
                    }
                }
            }
        }

        return static_cast<int>(antinodes.size());
    }
}