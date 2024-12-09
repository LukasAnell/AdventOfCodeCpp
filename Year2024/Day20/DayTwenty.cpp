//
// Created by Lukas on 12/9/2024.
//

#include "DayTwenty.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwenty::DayTwenty(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 20, isSample);
    }

    int DayTwenty::partOne() const {

    }
} // Year2024