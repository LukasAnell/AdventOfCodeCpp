//
// Created by Lukas on 8/30/2024.
//

#ifndef DAYSEVEN_H
#define DAYSEVEN_H
#include <string>
#include <vector>


class DaySeven {
public:
    std::vector<std::string> fileContents;

    explicit DaySeven(const std::string &fileName);
    [[nodiscard]] int partOne() const;
    // [[nodiscard]] int partTwo() const;
};



#endif //DAYSEVEN_H
