//
// Created by Lukas on 8/28/2024.
//

#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>


class utils {
    public:
    static std::vector<std::string> readFile(const std::string& fileName, int year, int dayNumber, bool isSample);
};



#endif //UTILS_H
