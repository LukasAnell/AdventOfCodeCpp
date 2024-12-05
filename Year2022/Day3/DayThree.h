//
// Created by Lukas on 8/28/2024.
//

#ifndef YEAR2022_DAYTHREE_H
#define YEAR2022_DAYTHREE_H
#include <string>
#include <vector>

namespace Year2022 {
    class DayThree {
    public:
        std::vector<std::string> fileContents;

        explicit DayThree(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
        static bool checkOthers(char character, const std::vector<std::string> &rucksacks, const std::pair<int, int> &rucksackIndices);
    };
}

#endif //YEAR2022_DAYTHREE_H
