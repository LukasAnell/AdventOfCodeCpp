//
// Created by Lukas on 8/28/2024.
//

#ifndef DAYTHREE_H
#define DAYTHREE_H
#include <string>
#include <vector>


class DayThree {
public:
    std::vector<std::string> fileContents;

    explicit DayThree(const std::string& fileName);
    [[nodiscard]] int partOne() const;
    [[nodiscard]] int partTwo() const;
};



#endif //DAYTHREE_H
