//
// Created by Lukas on 12/9/2024.
//

#include "DayTwentyFour.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwentyFour::DayTwentyFour(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 24, isSample);
    }

    int DayTwentyFour::partOne() const {

    }
} // Year2024