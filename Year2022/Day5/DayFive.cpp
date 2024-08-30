//
// Created by Lukas on 8/29/2024.
//

#include "DayFive.h"
#include "../../utils.h"

DayFive::DayFive(const std::string &fileName) {
    fileContents = utils::readFile(fileName, 4);
}

char DayFive::partOne() const {
    std::vector<std::vector<char>> stacks;
    for(const auto &fileContent : fileContents) {
        std::vector<char> currentLine;
        for(int j = 0; j < fileContent.size(); j++) {
            if(j % 4 == 0) {
                currentLine.push_back(fileContent.at(j + 1));
            }
        }
        stacks.push_back(currentLine);
    }
    
}