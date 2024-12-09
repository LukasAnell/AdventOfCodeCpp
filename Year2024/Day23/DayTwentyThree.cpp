//
// Created by Lukas on 12/9/2024.
//

#include "DayTwentyThree.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwentyThree::DayTwentyThree(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 23, isSample);
    }

    int DayTwentyThree::partOne() const {

    }
} // Year2024