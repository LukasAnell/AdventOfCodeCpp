//
// Created by Lukas on 12/4/2024.
//

#include "DayThree.h"

#include <iostream>
#include <bits/regex.h>

#include "../../utils.h"

namespace Year2024 {
    DayThree::DayThree(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 3);
    }

    int DayThree::partOne() const {
        int total = 0;
        for (const std::string& row : fileContents) {
            for (int i = 0; i < row.size(); i++) {

            }
        }
        return total;
    }

}