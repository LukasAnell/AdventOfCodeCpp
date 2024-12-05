//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYSEVEN_H
#define YEAR2024_DAYSEVEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySeven {
    public:
        std::vector<std::string> fileContents;

        explicit DaySeven(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYSEVEN_H
