//
// Created by Lukas on 12/9/2024.
//

#include "DayEighteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayEighteen::DayEighteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 18, isSample);
    }

    int DayEighteen::partOne() const {

    }
} // Year2024