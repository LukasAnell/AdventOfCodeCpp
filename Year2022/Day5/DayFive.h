//
// Created by Lukas on 8/29/2024.
//

#ifndef YEAR2022_DAYFIVE_H
#define YEAR2022_DAYFIVE_H
#include <string>
#include <vector>

namespace Year2022 {
    class DayFive {
    public:
        std::vector<std::string> fileContents;

        explicit DayFive(const std::string& fileName);
        [[nodiscard]] std::string partOne() const;
        [[nodiscard]] std::string partTwo() const;
        static int findMaxColumnLength(const std::vector<std::vector<char>>& vec) ;

    };
}

#endif //YEAR2022_DAYFIVE_H
