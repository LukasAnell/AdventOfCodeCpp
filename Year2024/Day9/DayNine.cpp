//
// Created by Lukas on 12/5/2024.
//

#include "DayNine.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayNine::DayNine(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 9, isSample);
    }

    int DayNine::partOne() const {

    }
}