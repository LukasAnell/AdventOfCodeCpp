//
// Created by Lukas on 12/9/2024.
//

#include "DayTwentyFive.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwentyFive::DayTwentyFive(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 25, isSample);
    }

    int DayTwentyFive::partOne() const {

    }
} // Year2024