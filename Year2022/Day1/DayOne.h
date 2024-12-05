//
// Created by Lukas on 8/28/2024.
//

#ifndef YEAR2022_DAYONE_H
#define YEAR2022_DAYONE_H
#include <string>
#include <vector>

namespace Year2022 {
    class DayOne {
    public:
        std::vector<std::string> fileContents;

        explicit DayOne(const std::string& fileName);
        [[nodiscard]] int bothParts(int topX) const;
    };
}

#endif //YEAR2022_DAYONE_H
