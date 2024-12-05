//
// Created by Lukas on 12/5/2024.
//

#include "DaySix.h"

#include "../../utils.h"
#include <string>

namespace Year2024 {
    DaySix::DaySix(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 6);
    }

    int DaySix::partOne() const {

    }
}