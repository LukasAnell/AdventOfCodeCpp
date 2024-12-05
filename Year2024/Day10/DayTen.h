//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYTEN_H
#define YEAR2024_DAYTEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayTen {
    public:
        std::vector<std::string> fileContents;

        explicit DayTen(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYTEN_H
