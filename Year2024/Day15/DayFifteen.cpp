//
// Created by Lukas on 12/9/2024.
//

#include "DayFifteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayFifteen::DayFifteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 15, isSample);
    }

    int DayFifteen::partOne() const {

    }
} // Year2024