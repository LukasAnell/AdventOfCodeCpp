//
// Created by Lukas on 12/9/2024.
//

#include "DaySixteen.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DaySixteen::DaySixteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 16, isSample);
    }

    int DaySixteen::partOne() const {

    }
} // Year2024