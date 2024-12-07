//
// Created by Lukas on 12/3/2024.
//

#include "DayOne.h"

#include "../../Utils/utils.h"
#include <algorithm>

namespace Year2024 {
    DayOne::DayOne(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 1, isSample);
    }

    std::pair<int, int> DayOne::constructNums(const std::string& input) {
        int numOne = stoi(input.substr(0, input.find(' ')));
        int numTwo = stoi(input.substr(input.find(' ')));
        return {numOne, numTwo};
    }

    std::pair<std::vector<int>, std::vector<int>> DayOne::constructCols() const {
        std::vector<int> colOne;
        std::vector<int> colTwo;
        for (const auto& row : fileContents) {
            auto [first, second] = constructNums(row);
            colOne.push_back(first);
            colTwo.push_back(second);
        }
        return {colOne, colTwo};
    }

    int DayOne::partOne() const {
        auto [first, second] = constructCols();
        std::ranges::sort(first);
        std::ranges::sort(second);

        int distance = 0;
        for (int i = 0; i < first.size(); i++) {
            distance += abs(first.at(i) - second.at(i));
        }
        return distance;
    }

    int DayOne::partTwo() const {
        auto [first, second] = constructCols();
        int score = 0;
        for (const int firstRowNum : first) {
            int count = 0;
            for (const int secondRowNum : second) {
                if (firstRowNum == secondRowNum) {
                    count++;
                }
            }
            score += firstRowNum * count;
        }
        return score;
    }

}