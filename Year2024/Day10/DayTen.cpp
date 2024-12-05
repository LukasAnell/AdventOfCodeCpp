//
// Created by Lukas on 12/5/2024.
//

#include "DayTen.h"

#include "../../utils.h"
#include <string>

namespace Year2024 {
    DayTen::DayTen(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 10);
    }

    int DayTen::partOne() const {

    }
}