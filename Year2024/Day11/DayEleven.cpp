//
// Created by Lukas on 12/9/2024.
//

#include "DayEleven.h"

#include "../../Utils/utils.h"
#include <deque>
#include <iostream>
#include <numeric>
#include <ostream>
#include <string>
#include <unordered_map>

namespace Year2024 {
    DayEleven::DayEleven(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 11, isSample);
    }

    long long DayEleven::bothParts(const int iterations) const {
        std::unordered_map<long long, long long> stonesDict;
        std::string numStr;
        for (const char ch : fileContents[0]) {
            if (ch == ' ') {
                if (!numStr.empty()) {
                    stonesDict[stoll(numStr)]++;
                    numStr.clear();
                }
            } else {
                numStr += ch;
            }
        }
        if (!numStr.empty()) {
            stonesDict[stoll(numStr)]++;
        }

        for (int i = 0; i < iterations; i++) {
            std::vector<std::pair<long long, long long>> stonesList(stonesDict.begin(), stonesDict.end());
            for (const auto& [key, count] : stonesList) {
                stonesDict[key] -= count;
                if (key == 0) {
                    stonesDict[1] += count;
                } else {
                    std::string digits = std::to_string(key);
                    if (digits.size() % 2 == 1) {
                        stonesDict[key * 2024] += count;
                    } else {
                        stonesDict[stoll(digits.substr(0, digits.size() / 2))] += count;
                        stonesDict[stoll(digits.substr(digits.size() / 2))] += count;
                    }
                }
            }
        }

        return std::accumulate(stonesDict.begin(), stonesDict.end(), 0LL, [](unsigned long long sum, const auto& pair) {
            return sum + pair.second;
        });
    }


    long long DayEleven::partOne() const {
        return bothParts(25);
    }

    long long DayEleven::partTwo() const {
        return bothParts(75);
    }

} // Year2024