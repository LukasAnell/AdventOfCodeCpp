//
// Created by Lukas on 12/9/2024.
//

#include "DayFourteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayFourteen::DayFourteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 14, isSample);
    }

    int DayFourteen::partOne() const {

    }
} // Year2024