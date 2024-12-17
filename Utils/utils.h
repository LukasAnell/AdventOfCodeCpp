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
    static std::vector<std::string> splitString(const std::string& input, const std::string& delimiter);
    static std::vector<int> extractInts(const std::string& str);
};



#endif //UTILS_H
