//
// Created by Lukas on 8/28/2024.
//

#include "DayThree.h"

#include "../../Utils/utils.h"
#include <map>

namespace Year2022 {
    DayThree::DayThree(const std::string &fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2022, 3, isSample);
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

            std::map<int, std::pair<int, int>> numMap;
            numMap.emplace(0, std::make_pair(1, 2));
            numMap.emplace(1, std::make_pair(0, 2));
            numMap.emplace(2, std::make_pair(0, 1));

            bool foundInBoth = false;
            for(int j = 0; j < rucksacks.size(); j++) {
                for(int k = 0; k < rucksacks[j].size(); k++) {
                    foundInBoth = checkOthers(rucksacks[j].at(k), rucksacks, numMap.at(j));
                    if(foundInBoth) {
                        sum += priorityMap.at(rucksacks[j].at(k));
                        break;
                    }
                }
                if(foundInBoth) {
                    break;
                }
            }
        }
        return sum;
    }

    bool DayThree::checkOthers(const char character, const std::vector<std::string> &rucksacks, const std::pair<int, int> &rucksackIndices) {
        const std::string& first = rucksacks[rucksackIndices.first];
        const std::string& second = rucksacks[rucksackIndices.second];

        bool foundInFirst = false;
        for(int i = 0; i < first.length(); i++) {
            if(character == first.at(i)) {
                foundInFirst = true;
                break;
            }
        }

        bool foundInSecond = false;
        for(int i = 0; i < second.length(); i++) {
            if(character == second.at(i)) {
                foundInSecond = true;
                break;
            }
        }

        return foundInFirst && foundInSecond;
    }
}