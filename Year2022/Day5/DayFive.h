//
// Created by Lukas on 8/29/2024.
//

#ifndef DAYFIVE_H
#define DAYFIVE_H
#include <string>
#include <vector>


class DayFive {
public:
    std::vector<std::string> fileContents;

    explicit DayFive(const std::string& fileName);
    [[nodiscard]] char partOne() const;
    [[nodiscard]] int partTwo() const;

};



#endif //DAYFIVE_H
