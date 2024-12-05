//
// Created by Lukas on 12/5/2024.
//

#include "DayEight.h"

#include "../../utils.h"
#include <string>

namespace Year2024 {
    DayEight::DayEight(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 8);
    }

    int DayEight::partOne() const {

    }
}