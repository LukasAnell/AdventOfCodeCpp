//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYTWENTYFIVE_H
#define YEAR2024_DAYTWENTYFIVE_H
#include <string>
#include <vector>

namespace Year2024 {
    class DayTwentyFive {
    public:
        std::vector<std::string> fileContents;

        explicit DayTwentyFive(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
} // Year2024

#endif //YEAR2024_DAYTWENTYFIVE_H