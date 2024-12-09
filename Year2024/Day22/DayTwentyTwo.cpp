//
// Created by Lukas on 12/9/2024.
//

#include "DayTwentyTwo.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwentyTwo::DayTwentyTwo(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 22, isSample);
    }

    int DayTwentyTwo::partOne() const {

    }
} // Year2024