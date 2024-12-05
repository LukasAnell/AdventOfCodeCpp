//
// Created by Lukas on 12/5/2024.
//

#include "DayFive.h"

#include <algorithm>
#include <map>

#include "../../utils.h"

namespace Year2024 {
    DayFive::DayFive(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 5);
    }

    int DayFive::partOne() const {
        int output = 0;
        std::vector<std::pair<int, int>> rules;

        for (const std::string& line : fileContents) {
            if (line[2] == '|') {
                int first = stoi(line.substr(0, 2));
                int second = stoi(line.substr(3, 2));
                rules.emplace_back(first, second);
            }

            if (line[2] == ',') {
                std::vector<int> pageNums;
                std::string lineCopy = line;
                int index = lineCopy.find(',');
                while (index != -1) {
                    pageNums.emplace_back(stoi(lineCopy.substr(0, index)));
                    lineCopy = lineCopy.substr(index + 1);
                    index = lineCopy.find(',');
                }
                pageNums.emplace_back(stoi(lineCopy.substr(0, index)));

                bool isValid = true;
                for (int i = 0; i < pageNums.size(); i++) {
                    for (auto &[first, second] : rules) {
                        if (second == pageNums[i]) {
                            for (int k = i; k < pageNums.size(); k++) {
                                if (pageNums[k] == first) {
                                    isValid = false;
                                    break;
                                }
                            }
                        }
                        if (!isValid) {
                            break;
                        }
                    }
                    if(!isValid) {
                        break;
                    }
                }
                if (isValid) {
                    output += pageNums[pageNums.size() / 2];
                }
            }
        }

        return output;
    }

    int DayFive::partTwo() const {
        int output = 0;
        std::vector<std::pair<int, int>> rules;

        for (const std::string& line : fileContents) {
            if (line[2] == '|') {
                int first = stoi(line.substr(0, 2));
                int second = stoi(line.substr(3, 2));
                rules.emplace_back(first, second);
            }

            if (line[2] == ',') {
                std::vector<int> pageNums;
                std::string lineCopy = line;
                int index = lineCopy.find(',');
                while (index != -1) {
                    pageNums.emplace_back(std::stoi(lineCopy.substr(0, index)));
                    lineCopy = lineCopy.substr(index + 1);
                    index = lineCopy.find(',');
                }
                pageNums.emplace_back(std::stoi(lineCopy.substr(0, index)));

                bool isValid = true;
                for (int i = 0; i < pageNums.size(); i++) {
                    for (auto &[first, second] : rules) {
                        if (second == pageNums[i]) {
                            for (int k = i; k < pageNums.size(); k++) {
                                if (pageNums[k] == first) {
                                    isValid = false;
                                    break;
                                }
                            }
                        }
                        if (!isValid) {
                            break;
                        }
                    }
                    if (!isValid) {
                        break;
                    }
                }

                if (!isValid) {
                    std::ranges::sort(pageNums, [&](int a, int b) {
                        return customComparator(a, b, rules);
                    });
                    output += pageNums[pageNums.size() / 2];
                }
            }
        }

        return output;
    }

    bool DayFive::customComparator(const int a, const int b, const std::vector<std::pair<int, int>>& rules) {
        for (const auto&[first, second] : rules) {
            if (first == a && second == b) {
                return true;
            }
            if (first == b && second == a) {
                return false;
            }
        }
        return a < b;
    }

}