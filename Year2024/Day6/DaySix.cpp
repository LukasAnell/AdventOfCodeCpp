//
// Created by Lukas on 12/5/2024.
//

#include "DaySix.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DaySix::DaySix(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 6, isSample);
    }

    int DaySix::partOne() const {

    }
}