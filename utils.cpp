//
// Created by Lukas on 8/28/2024.
//

#include "utils.h"

#include <fstream>
#include <string.h>

std::vector<std::string> utils::readFile(const std::string& fileName, const int dayNumber) {
    std::ifstream file("Year2022/Day" +  std::to_string(dayNumber) + "/" + fileName + ".txt");
    std::string str;
    std::vector<std::string> result;
    while (std::getline(file, str)) {
        result.push_back(str);
    }
    return result;
}
