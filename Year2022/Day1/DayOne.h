//
// Created by Lukas on 8/28/2024.
//

#ifndef DAYONE_H
#define DAYONE_H
#include <string>
#include <vector>


class DayOne {
public:
    std::vector<std::string> fileContents;

    explicit DayOne(const std::string& fileName);
    [[nodiscard]] int bothParts(int topX) const;
};



#endif //DAYONE_H
