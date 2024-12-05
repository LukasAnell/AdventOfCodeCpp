//
// Created by Lukas on 12/5/2024.
//

#include "DayNine.h"

#include "../../utils.h"
#include <string>

namespace Year2024 {
    DayNine::DayNine(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 9);
    }

    int DayNine::partOne() const {

    }
}