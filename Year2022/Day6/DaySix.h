//
// Created by Lukas on 8/30/2024.
//

#ifndef YEAR2022_DAYSIX_H
#define YEAR2022_DAYSIX_H
#include <string>
#include <vector>

namespace Year2022 {
    class DaySix {
    public:
        std::vector<std::string> fileContents;

        explicit DaySix(const std::string &fileName);
        [[nodiscard]] int bothParts(int distinctAmount) const;
    };
}

#endif //YEAR2022_DAYSIX_H
