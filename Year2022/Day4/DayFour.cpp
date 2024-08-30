//
// Created by Lukas on 8/29/2024.
//

#include "DayFour.h"

#include <sstream>

#include "../../utils.h"

DayFour::DayFour(const std::string& fileName) {
    fileContents = utils::readFile(fileName, 4);
}

int DayFour::partOne() const {
    int count = 0;
    for(std::string line : fileContents) {
        std::vector<std::string> separatedByComma;
        std::stringstream ss(line);
        while(std::getline(ss, line, ',')) {
            separatedByComma.push_back(line);
        }

        std::pair<int, int> first = std::make_pair(
            std::stoi(separatedByComma[0].substr(0, separatedByComma[0].find('-', 0))),
            std::stoi(separatedByComma[0].substr(separatedByComma[0].find('-') + 1, separatedByComma[0].length()))
            );
        std::pair<int, int> second = std::make_pair(
            std::stoi(separatedByComma[1].substr(0, separatedByComma[1].find('-', 0))),
            std::stoi(separatedByComma[1].substr(separatedByComma[1].find('-') + 1, separatedByComma[0].length()))
            );

        if(first.first <= second.first && first.second >= second.second) {
            count++;
        } else if(second.first <= first.first && second.second >= first.second) {
            count++;
        }
    }
    return count;
}

int DayFour::partTwo() const {
    int count = 0;
    for(std::string line : fileContents) {
        std::vector<std::string> separatedByComma;
        std::stringstream ss(line);
        while(std::getline(ss, line, ',')) {
            separatedByComma.push_back(line);
        }

        std::pair<int, int> first = std::make_pair(
            std::stoi(separatedByComma[0].substr(0, separatedByComma[0].find('-', 0))),
            std::stoi(separatedByComma[0].substr(separatedByComma[0].find('-') + 1, separatedByComma[0].length()))
            );
        std::pair<int, int> second = std::make_pair(
            std::stoi(separatedByComma[1].substr(0, separatedByComma[1].find('-', 0))),
            std::stoi(separatedByComma[1].substr(separatedByComma[1].find('-') + 1, separatedByComma[0].length()))
            );

        if(first.first <= second.second && second.first <= first.second) {
            count++;
        }
    }
    return count;
}

