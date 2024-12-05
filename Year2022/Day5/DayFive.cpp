//
// Created by Lukas on 8/29/2024.
//

#include "DayFive.h"

#include "../../utils.h"
#include <iostream>
#include <ostream>

namespace Year2022 {
    DayFive::DayFive(const std::string &fileName) {
        fileContents = utils::readFile(fileName, 5);
    }

    std::string DayFive::partOne() const {
        std::vector<std::vector<char>> stacks;
        int leftOff;
        for(int i = 0; i < fileContents.size() - 1; i++) {
            if(!fileContents[i + 1].empty()) {
                std::vector<char> currentLine;
                for(int j = 0; j < fileContents[i].size(); j++) {
                    if(j % 4 == 0) {
                        currentLine.push_back(fileContents[i].at(j + 1));
                    }
                }
                stacks.push_back(currentLine);
            } else {
                leftOff = i + 2;
                break;
            }
        }

        std::vector<std::vector<char>> convertedStacks;
        const int maxColumnLength = findMaxColumnLength(stacks);
        for(int c = 0; c < maxColumnLength; c++) {
            std::vector<char> currentCol;
            for(auto & stack : stacks) {
                if(c < stack.size() && stack[c] != '\253' && !std::isspace(stack[c])) {
                    currentCol.push_back(stack[c]);
                }
            }
            convertedStacks.push_back(currentCol);
        }

        std::vector<std::vector<int>> instructions;
        for(int i = leftOff; i < fileContents.size(); i++) {
            std::vector<int> currentInstruction;
            for(int j = 0; j < fileContents[i].length(); j++) {
                int k = j;
                std::string currentNumber;
                while(k < fileContents[i].length() && isdigit(fileContents[i].at(k))) {
                    currentNumber += fileContents[i].at(k);
                    k++;
                }
                if(!currentNumber.empty()) {
                    currentInstruction.push_back(std::stoi(currentNumber));
                    j = k;
                }
            }
            instructions.push_back(currentInstruction);
        }

        for(std::vector<int> currentInstruction : instructions) {
            const int amount = currentInstruction[0];
            const int start = currentInstruction[1] - 1;
            const int end = currentInstruction[2] - 1;
            if (start >= 0 && start < convertedStacks.size() && end >= 0 && end < convertedStacks.size()) {
                for(int i = 0; i < amount; i++) {
                    if (!convertedStacks[start].empty()) {
                        char poppedOff = convertedStacks[start].front();
                        convertedStacks[start].erase(convertedStacks[start].begin());
                        convertedStacks[end].insert(convertedStacks[end].begin(), poppedOff);
                    }
                }
            }
        }

        std::string out = "";
        for(std::vector<char> stack : convertedStacks) {
            if (!stack.empty()) {
                out += stack.front();
            }
        }

        return out;
    }


    int DayFive::findMaxColumnLength(const std::vector<std::vector<char>> &vec) {
        int maxLength = 0;
        for (const auto& column : vec) {
            maxLength = std::max(maxLength, static_cast<int>(column.size()));
        }
        return maxLength;
    }

    std::string DayFive::partTwo() const {
        std::vector<std::vector<char>> stacks;
        int leftOff;
        for(int i = 0; i < fileContents.size() - 1; i++) {
            if(!fileContents[i + 1].empty()) {
                std::vector<char> currentLine;
                for(int j = 0; j < fileContents[i].size(); j++) {
                    if(j % 4 == 0) {
                        currentLine.push_back(fileContents[i].at(j + 1));
                    }
                }
                stacks.push_back(currentLine);
            } else {
                leftOff = i + 2;
                break;
            }
        }

        std::vector<std::vector<char>> convertedStacks;
        const int maxColumnLength = findMaxColumnLength(stacks);
        for(int c = 0; c < maxColumnLength; c++) {
            std::vector<char> currentCol;
            for(auto & stack : stacks) {
                if(c < stack.size() && stack[c] != '\253' && !std::isspace(stack[c])) {
                    currentCol.push_back(stack[c]);
                }
            }
            convertedStacks.push_back(currentCol);
        }

        std::vector<std::vector<int>> instructions;
        for(int i = leftOff; i < fileContents.size(); i++) {
            std::vector<int> currentInstruction;
            for(int j = 0; j < fileContents[i].length(); j++) {
                int k = j;
                std::string currentNumber;
                while(k < fileContents[i].length() && isdigit(fileContents[i].at(k))) {
                    currentNumber += fileContents[i].at(k);
                    k++;
                }
                if(!currentNumber.empty()) {
                    currentInstruction.push_back(std::stoi(currentNumber));
                    j = k;
                }
            }
            instructions.push_back(currentInstruction);
        }

        for(std::vector<int> currentInstruction : instructions) {
            const int amount = currentInstruction[0];
            const int start = currentInstruction[1] - 1;
            const int end = currentInstruction[2] - 1;
            if (start >= 0 && start < convertedStacks.size() && end >= 0 && end < convertedStacks.size()) {
                std::vector<int> poppedOffVector;
                for(int i = 0; i < amount; i++) {
                    if (!convertedStacks[start].empty()) {
                        char poppedOff = convertedStacks[start].front();
                        convertedStacks[start].erase(convertedStacks[start].begin());
                        poppedOffVector.push_back(poppedOff);
                    }
                }
                convertedStacks[end].insert(convertedStacks[end].begin(), poppedOffVector.begin(), poppedOffVector.end());
            }
        }

        std::string out = "";
        for(std::vector<char> stack : convertedStacks) {
            if (!stack.empty()) {
                out += stack.front();
            }
        }

        return out;
    }
}