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

    long long DayThirteen::constructNum(const std::string &line, const int index) {
        std::string out = "";
        for (int i = index; i < line.size(); i++) {
            if (line[i] == ',') {
                break;
            }
            out += line[i];
        }
        return std::stoll(out);
    }

    std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> DayThirteen::constructPrizesVec(const long long added) const {
        std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> prizesVec;
        for (int i = 0; i < fileContents.size() - 2; i += 4) {
            std::string line = fileContents[i];
            std::pair aPair = {stoi(line.substr(line.find('X') + 2, 2)), stoi(line.substr(line.find('Y') + 2, 2))};
            line = fileContents[i + 1];
            std::pair bPair = {stoi(line.substr(line.find('X') + 2, 2)), stoi(line.substr(line.find('Y') + 2, 2))};
            line = fileContents[i + 2];
            std::pair prizeLoc = {constructNum(line, line.find('X') + 2) + added, constructNum(line, line.find('Y') + 2) + added};
            std::vector<std::pair<char, std::pair<long long, long long>>> buttons;
            buttons.emplace_back(std::pair('A', std::pair(aPair.first, aPair.second)));
            buttons.emplace_back(std::pair('B', std::pair(bPair.first, bPair.second)));

            prizesVec.push_back({{prizeLoc.first, prizeLoc.second}, buttons});
        }
        return prizesVec;
    }

    long long DayThirteen::getTokens(std::vector<std::pair<std::pair<long long, long long>, std::vector<std::pair<char, std::pair<long long, long long>>>>> prizesVec) {
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

    int DayThirteen::partOne() const {
        return getTokens(constructPrizesVec(0));
    }

    long long DayThirteen::partTwo() const {
        return getTokens(constructPrizesVec(10000000000000));
    }
} // Year2024