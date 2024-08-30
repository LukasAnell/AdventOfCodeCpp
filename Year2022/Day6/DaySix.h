//
// Created by Lukas on 8/30/2024.
//

#ifndef DAYSIX_H
#define DAYSIX_H
#include <string>
#include <vector>


class DaySix {
public:
    std::vector<std::string> fileContents;

    explicit DaySix(const std::string &fileName);
    [[nodiscard]] int bothParts(int distinctAmount) const;
};



#endif //DAYSIX_H
