//
// Created by Lukas on 12/9/2024.
//

#include "DayThirteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayThirteen::DayThirteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 13, isSample);
    }

    int DayThirteen::partOne() const {

    }
} // Year2024