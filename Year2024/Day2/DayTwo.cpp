//
// Created by Lukas on 12/3/2024.
//

#include "DayTwo.h"

#include "../../Utils/utils.h"
#include <iostream>
#include <sstream>

namespace Year2024 {
    DayTwo::DayTwo(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 2, isSample);
    }

    bool DayTwo::incrOrDecr(const std::vector<int>& vector) {
        bool increasing = true;
        for (int i = 1; i < vector.size(); i++) {
            if (vector.at(i) < vector.at(i - 1)) {
                increasing = false;
                break;
            }
        }

        bool decreasing = true;
        for (int i = 1; i < vector.size(); i++) {
            if (vector.at(i) > vector.at(i - 1)) {
                decreasing = false;
                break;
            }
        }

        return increasing || decreasing;
    }

    bool DayTwo::withinRange(const std::vector<int>& vector) {
        for (int i = 1; i < vector.size(); i++) {
            if (const int difference = abs(vector.at(i) - vector.at(i - 1)); difference > 3 || difference < 1) {
                return false;
            }
        }
        return true;
    }

    int DayTwo::partOne() const {
        int count = 0;
        for (const std::string& row : fileContents) {
            std::stringstream rowSs(row);
            std::vector<int> rowVector;
            std::string segment;
            while (std::getline(rowSs, segment, ' ')) {
                rowVector.push_back(stoi(segment));
            }

            const bool incrOrDecr = DayTwo::incrOrDecr(rowVector);
            if (const bool withinRange = DayTwo::withinRange(rowVector); incrOrDecr && withinRange) {
                count++;
            }
        }
        return count;
    }

    int DayTwo::partTwo() const {
        int count = 0;
        for (const std::string& row : fileContents) {
            std::stringstream rowSs(row);
            std::vector<int> rowVector;
            std::string segment;
            while (std::getline(rowSs, segment, ' ')) {
                rowVector.push_back(stoi(segment));
            }

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
