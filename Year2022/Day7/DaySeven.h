//
// Created by Lukas on 8/30/2024.
//

#ifndef YEAR2022_DAYSEVEN_H
#define YEAR2022_DAYSEVEN_H
#include <string>
#include <vector>

namespace Year2022 {
    class DaySeven {
    public:
        std::vector<std::string> fileContents;

        explicit DaySeven(const std::string &fileName);
        [[nodiscard]] int partOne() const;
        // [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2022_DAYSEVEN_H
