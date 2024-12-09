//
// Created by Lukas on 12/9/2024.
//

#include "DaySeventeen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DaySeventeen::DaySeventeen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 17, isSample);
    }

    int DaySeventeen::partOne() const {

    }
} // Year2024