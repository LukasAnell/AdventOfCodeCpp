//
// Created by Lukas on 8/28/2024.
//

#include "utils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>

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

std::vector<std::string> utils::splitString(const std::string& input, const std::string& delimiter) {
    std::vector<std::string> output;
    size_t start = 0;
    size_t end = input.find(delimiter);
    while (end != std::string::npos) {
        output.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    output.push_back(input.substr(start, end));
    return output;
}

std::vector<int> utils::extractInts(const std::string& str) {
    std::vector<int> result;
    const std::regex re("-?\\d+");
    std::sregex_iterator next(str.begin(), str.end(), re);
    const std::sregex_iterator end;
    while (next != end) {
        result.push_back(std::stoi(next->str()));
        ++next;
    }
    return result;
}