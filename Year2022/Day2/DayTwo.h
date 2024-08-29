//
// Created by Lukas on 8/28/2024.
//

#ifndef DAYTWO_H
#define DAYTWO_H
#include <string>
#include <vector>


class DayTwo {
public:
    std::vector<std::string> fileContents;

    explicit DayTwo(const std::string& fileName);
    [[nodiscard]] int partOne() const;
    [[nodiscard]] int partTwo() const;
};



#endif //DAYTWO_H
