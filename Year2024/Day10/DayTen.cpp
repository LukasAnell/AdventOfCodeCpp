//
// Created by Lukas on 12/5/2024.
//

#include "DayTen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTen::DayTen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 10, isSample);
    }

    int DayTen::partOne() const {

    }
}