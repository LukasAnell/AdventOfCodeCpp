//
// Created by Lukas on 12/9/2024.
//

#include "DayTwelve.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwelve::DayTwelve(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 12, isSample);
    }

    int DayTwelve::partOne() const {

    }
} // Year2024