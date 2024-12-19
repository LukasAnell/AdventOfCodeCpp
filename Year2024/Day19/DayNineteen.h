//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYNINETEEN_H
#define YEAR2024_DAYNINETEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayNineteen {
    public:
        std::vector<std::string> fileContents;

        explicit DayNineteen(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] long long partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYNINETEEN_H
