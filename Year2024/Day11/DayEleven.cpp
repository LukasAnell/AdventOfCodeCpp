//
// Created by Lukas on 12/9/2024.
//

#include "DayEleven.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayEleven::DayEleven(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 11, isSample);
    }

    int DayEleven::partOne() const {

    }
} // Year2024