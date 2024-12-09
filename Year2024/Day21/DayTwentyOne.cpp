//
// Created by Lukas on 12/9/2024.
//

#include "DayTwentyOne.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwentyOne::DayTwentyOne(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 21, isSample);
    }

    int DayTwentyOne::partOne() const {

    }
} // Year2024