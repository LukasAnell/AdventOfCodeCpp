//
// Created by Lukas on 12/4/2024.
//

#ifndef YEAR2024_DAYTHREE_H
#define YEAR2024_DAYTHREE_H
#include <string>
#include <vector>


namespace Year2024 {
    class DayThree {
    public:
        std::vector<std::string> fileContents;

        explicit DayThree(const std::string& fileName, bool isSample);
        [[nodiscard]] int partOne() const;
        [[nodiscard]] int partTwo() const;
    };
}



#endif //YEAR2024_DAYTHREE_H
