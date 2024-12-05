//
// Created by Lukas on 8/28/2024.
//

#include "DayOne.h"

#include "../../utils.h"
#include <iostream>
#include <ostream>

namespace Year2022 {
    DayOne::DayOne(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 1);
    }

    int DayOne::bothParts(const int topX) const {
        std::vector<int> allSums;
        int currentCount = 0;
        int i = 0;
        while(i < fileContents.size()) {
            if(!fileContents[i].empty()) {
                currentCount += std::stoi(fileContents[i]);
            } else {
                allSums.push_back(currentCount);
                currentCount = 0;
            }
            i++;
        }
        allSums.push_back(currentCount);

        int sumTopX = 0;
        int max = INT_MIN;
        for(i = 0; i < topX; i++) {
            int index = 0;
            for(int j = 0; j < allSums.size(); j++) {
                if(const int current = allSums[j]; current > max) {
                    max = current;
                    index = j;
                }
            }
            sumTopX += max;
            max = INT_MIN;
            allSums.erase(allSums.begin() + index);
        }
        return sumTopX;
    }
}