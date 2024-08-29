//
// Created by Lukas on 8/28/2024.
//

#include "DayThree.h"

#include <map>

#include "../../utils.h"

DayThree::DayThree(const std::string &fileName) {
    fileContents = utils::readFile(fileName, 3);
}

int DayThree::partOne() const {
    std::map<char, int> priorityMap;
    int i = 1;
    for(int j = 97; j < 123; j++) {
        priorityMap.emplace(static_cast<char>(j), i);
        i++;
    }
    for(int j = 65; j < 91; j++) {
        priorityMap.emplace(static_cast<char>(j), i);
        i++;
    }

    int sum = 0;
    for(const std::string& line : fileContents) {
        std::string firstCompartment = line.substr(0, line.length() / 2);
        std::string secondCompartment = line.substr(line.length() / 2);

        bool foundDuplicate = false;
        for(i = 0; i < firstCompartment.length(); i++) {
            if(secondCompartment.find(firstCompartment.at(i)) < secondCompartment.length()) {
                sum += priorityMap.at(firstCompartment.at(i));
                foundDuplicate = true;
                break;
            }
        }
    }

    return sum;
}

int DayThree::partTwo() const {
    std::map<char, int> priorityMap;
    int i = 1;
    for(int j = 97; j < 123; j++) {
        priorityMap.emplace(static_cast<char>(j), i);
        i++;
    }
    for(int j = 65; j < 91; j++) {
        priorityMap.emplace(static_cast<char>(j), i);
        i++;
    }

    int sum = 0;
    for(i = 0; i < fileContents.size(); i += 3) {
        std::vector<std::string> rucksacks;
        rucksacks.push_back(fileContents[i]);
        rucksacks.push_back(fileContents[i + 1]);
        rucksacks.push_back(fileContents[i + 2]);


    }
    return sum;
}

bool checkOthers(int num1, int num2) {

}

