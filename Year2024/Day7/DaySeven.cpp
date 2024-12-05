//
// Created by Lukas on 12/5/2024.
//

#include "DaySeven.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DaySeven::DaySeven(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 7, isSample);
    }

    int DaySeven::partOne() const {

    }
}