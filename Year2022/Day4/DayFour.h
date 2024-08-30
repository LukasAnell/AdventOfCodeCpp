//
// Created by Lukas on 8/29/2024.
//

#ifndef DAYFOUR_H
#define DAYFOUR_H
#include <string>
#include <vector>


class DayFour {
public:
    std::vector<std::string> fileContents;

    explicit DayFour(const std::string& fileName);
    [[nodiscard]] int partOne() const;
    [[nodiscard]] int partTwo() const;
};



#endif //DAYFOUR_H
