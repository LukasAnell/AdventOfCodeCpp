//
// Created by Lukas on 12/4/2024.
//

#ifndef YEAR2024_DAYFOUR_H
#define YEAR2024_DAYFOUR_H
#include <string>
#include <vector>


namespace Year2024 {
    class DayFour {
    public:
        std::vector<std::string> fileContents;

        explicit DayFour(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //DAYFOUR_H
