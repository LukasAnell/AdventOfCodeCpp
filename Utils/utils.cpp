//
// Created by Lukas on 8/28/2024.
//

#include "utils.h"

#include <filesystem>
#include <fstream>
#include <iostream>

std::vector<std::string> utils::readFile(const std::string& fileName, const int year, const int dayNumber, const bool isSample) {
    std::string fullFileName = "..\\Year" + std::to_string(year) + "\\";
    if (isSample) {
        fullFileName += "Sample";
    }
    fullFileName += "Inputs\\day" +  std::to_string(dayNumber) + fileName;
    std::ifstream file(fullFileName);

    std::vector<std::string> output;
    if (file.is_open()) {
        std::string line;
        while(std::getline(file, line)) {\
            if(line.empty()) {
                output.emplace_back("");
            } else {
                output.push_back(line);
            }
        }
    } else {
        std::cout << "File failed to open" << std::endl;
    }

    return output;
}
