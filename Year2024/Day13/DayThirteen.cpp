//
// Created by Lukas on 12/9/2024.
//

#include "DayThirteen.h"

#include <cmath>

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayThirteen::DayThirteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 13, isSample);
    }

    int DayThirteen::constructNum1(const std::string &line, const int index) {
        std::string out = "";
        for (int i = index; i < line.size(); i++) {
            if (line[i] == ',') {
                break;
            }
            out += line[i];
        }
        return stoi(out);
    }

    int DayThirteen::partOne() const {
        std::vector<std::pair<std::pair<int, int>, std::vector<std::pair<char, std::pair<int, int>>>>> prizesVec;
        for (int i = 0; i < fileContents.size() - 2; i += 4) {
            std::string line = fileContents[i];
            std::pair aPair = {stoi(line.substr(line.find('X') + 2, 2)), stoi(line.substr(line.find('Y') + 2, 2))};
            line = fileContents[i + 1];
            std::pair bPair = {stoi(line.substr(line.find('X') + 2, 2)), stoi(line.substr(line.find('Y') + 2, 2))};
            line = fileContents[i + 2];
            std::pair prizeLoc = {constructNum1(line, line.find('X') + 2), constructNum1(line, line.find('Y') + 2)};
            std::vector<std::pair<char, std::pair<int, int>>> buttons;
            buttons.emplace_back(std::pair('A', std::pair(aPair.first, aPair.second)));
            buttons.emplace_back(std::pair('B', std::pair(bPair.first, bPair.second)));

            prizesVec.push_back({{prizeLoc.first, prizeLoc.second}, buttons});
        }

        int totalTokens = 0;
        for (auto& prizeInstructions: prizesVec) {
            const std::pair aInstr = {prizeInstructions.second[0].second.first, prizeInstructions.second[0].second.second};
            const std::pair bInstr = {prizeInstructions.second[1].second.first, prizeInstructions.second[1].second.second};
            const std::pair prizeLoc = {prizeInstructions.first.first, prizeInstructions.first.second};

            int minTokens = INT_MAX;
            for (int a = 1; a < 100; a++) {
                for (int b = 1; b < 100; b++) {
                    const int currX = aInstr.first * a + bInstr.first * b;
                    const int currY = aInstr.second * a + bInstr.second * b;
                    if (currX == prizeLoc.first && currY == prizeLoc.second) {
                        minTokens = std::min(minTokens, 3 * a + b);
                    }
                }
            }
            if (minTokens != INT_MAX) {
                totalTokens += minTokens;
            }
        }
        return totalTokens;
    }

    long long DayThirteen::constructNum2(const std::string &line, const int index) {
        std::string out = "";
        for (int i = index; i < line.size(); i++) {
            if (line[i] == ',') {
                break;
            }
            out += line[i];
        }
        return std::stoll(out);
    }

    long long gcdExtended(long long a, long long b, long long &x, long long &y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        long long x1, y1;
        long long gcd = gcdExtended(b % a, a, x1, y1);
        x = y1 - (b / a) * x1;
        y = x1;
        return gcd;
    }

    long long DayThirteen::partTwo() const {
        std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> prizesVec;
        for (int i = 0; i < fileContents.size() - 2; i += 4) {
            std::string line = fileContents[i];
            std::pair aPair = {std::stoll(line.substr(line.find('X') + 2, line.find(',') - line.find('X') - 2)), std::stoll(line.substr(line.find('Y') + 2, line.find(',') - line.find('Y') - 2))};
            line = fileContents[i + 1];
            std::pair bPair = {std::stoll(line.substr(line.find('X') + 2, line.find(',') - line.find('X') - 2)), std::stoll(line.substr(line.find('Y') + 2, line.find(',') - line.find('Y') - 2))};
            line = fileContents[i + 2];
            std::pair prizeLoc = {constructNum2(line, line.find('X') + 2) + 10000000000000, constructNum2(line, line.find('Y') + 2) + 10000000000000};
            std::vector<std::pair<char, std::pair<long long, long long>>> buttons;
            buttons.emplace_back(std::pair('A', std::pair(aPair.first, aPair.second)));
            buttons.emplace_back(std::pair('B', std::pair(bPair.first, bPair.second)));

            prizesVec.push_back({{prizeLoc.first, prizeLoc.second}, buttons});
        }

        long long totalTokens = 0;
        for (auto&[prize, instructions]: prizesVec) {
            const std::pair aInstr = {instructions[0].second.first, instructions[0].second.second};
            const std::pair bInstr = {instructions[1].second.first, instructions[1].second.second};
            const std::pair prizeLoc = {prize.first, prize.second};

            const double bPresses = (static_cast<double>(aInstr.first) * prizeLoc.second - prizeLoc.first * aInstr.second) / (aInstr.first * bInstr.second - bInstr.first * aInstr.second);
            const double aPresses = (static_cast<double>(prizeLoc.first) - bPresses * bInstr.first) / (aInstr.first);

            if (aPresses < 0 || bPresses < 0 || trunc(bPresses) != bPresses || trunc(aPresses) != aPresses) {
                continue;
            }
            totalTokens += aPresses * 3 + bPresses;
        }
        return totalTokens;
    }
} // Year2024