//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYSIX_H
#define YEAR2024_DAYSIX_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySix {
    public:
        std::vector<std::string> fileContents;

        explicit DaySix(const std::string& fileName);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}

#endif //YEAR2024_DAYSIX_H
