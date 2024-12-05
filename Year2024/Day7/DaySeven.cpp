//
// Created by Lukas on 12/5/2024.
//

#include "DaySeven.h"

#include "../../utils.h"
#include <string>

namespace Year2024 {
    DaySeven::DaySeven(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 7);
    }

    int DaySeven::partOne() const {

    }
}