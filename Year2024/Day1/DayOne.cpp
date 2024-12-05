//
// Created by Lukas on 12/3/2024.
//

#include "DayOne.h"

#include <algorithm>

#include "../../utils.h"
namespace Year2024 {
    DayOne::DayOne(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 1);
    }

    int DayOne::partOne() const {
        std::vector<int> colOne;
        std::vector<int> colTwo;

        for (int i = 0; i < fileContents.size(); i++) {
            std::string row = fileContents.at(i);
            auto [first, second] = constructNums(row);
            colOne.push_back(first);
            colTwo.push_back(second);
        }

        std::ranges::sort(colOne);
        std::ranges::sort(colTwo);

        int distance = 0;
        for (int i = 0; i < colOne.size(); i++) {
            distance += abs(colOne.at(i) - colTwo.at(i));
        }
        return distance;
    }

    std::pair<int, int> DayOne::constructNums(const std::string& input) const {
        int numOne = stoi(input.substr(0, input.find(" ")));
        int numTwo = stoi(input.substr(input.find(" ")));
        return {numOne, numTwo};
    }

    int DayOne::partTwo() const {
        std::vector<int> colOne;
        std::vector<int> colTwo;

        for (int i = 0; i < fileContents.size(); i++) {
            std::string row = fileContents.at(i);
            auto [first, second] = constructNums(row);
            colOne.push_back(first);
            colTwo.push_back(second);
        }

        int score = 0;

        for (int firstRowNum : colOne) {
            int count = 0;
            for (int secondRowNum : colTwo) {
                if (firstRowNum == secondRowNum) {
                    count++;
                }
            }
            score += firstRowNum * count;
        }
        return score;
    }

}