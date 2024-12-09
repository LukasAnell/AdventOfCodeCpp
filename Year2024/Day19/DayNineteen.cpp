//
// Created by Lukas on 12/9/2024.
//

#include "DayNineteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayNineteen::DayNineteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 19, isSample);
    }

    int DayNineteen::partOne() const {

    }
} // Year2024