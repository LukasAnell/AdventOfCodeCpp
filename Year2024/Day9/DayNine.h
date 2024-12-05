//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYNINE_H
#define YEAR2024_DAYNINE_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayNine {
    public:
        std::vector<std::string> fileContents;

        explicit DayNine(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYNINE_H
