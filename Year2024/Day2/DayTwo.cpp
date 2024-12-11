//
// Created by Lukas on 12/3/2024.
//

#include "DayTwo.h"

#include <algorithm>

#include "../../Utils/utils.h"
#include <iostream>
#include <sstream>

namespace Year2024 {
    DayTwo::DayTwo(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 2, isSample);
    }

    bool DayTwo::incrOrDecr(const std::vector<int>& vector) {
        return std::ranges::is_sorted(vector, std::greater()) || std::ranges::is_sorted(vector, std::less());
    }

    bool DayTwo::withinRange(const std::vector<int>& vector) {
        for (int i = 1; i < vector.size(); i++) {
            if (const int difference = abs(vector.at(i) - vector.at(i - 1)); difference > 3 || difference < 1) {
                return false;
            }
        }
        return true;
    }

    std::vector<int> DayTwo::getRowVector(const std::string& row) {
        std::vector<int> rowVector;
        std::stringstream rowSs(row);
        std::string segment;
        while (std::getline(rowSs, segment, ' ')) {
            rowVector.push_back(stoi(segment));
        }
        return rowVector;
    }

    int DayTwo::partOne() const {
        int count = 0;
        for (const std::string& row : fileContents) {
            std::vector<int> rowVector = getRowVector(row);
            if (incrOrDecr(rowVector) && withinRange(rowVector)) {
                count++;
            }
        }
        return count;
    }

    int DayTwo::partTwo() const {
        int count = 0;
        for (const std::string& row : fileContents) {
            std::vector<int> rowVector = getRowVector(row);
            for (int i = 0; i < rowVector.size(); i++) {
                std::vector<int> newRowVector = rowVector;
                newRowVector.erase(newRowVector.begin() + i);
                if (incrOrDecr(newRowVector) && withinRange(newRowVector)) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
