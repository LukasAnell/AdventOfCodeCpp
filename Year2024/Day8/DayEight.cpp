//
// Created by Lukas on 12/5/2024.
//

#include "DayEight.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayEight::DayEight(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 8, isSample);
    }

    int DayEight::partOne() const {

    }
}