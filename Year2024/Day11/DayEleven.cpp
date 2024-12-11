//
// Created by Lukas on 12/9/2024.
//

#include "DayEleven.h"

#include "../../Utils/utils.h"
#include <numeric>
#include <unordered_map>

namespace Year2024 {
    DayEleven::DayEleven(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 11, isSample);
    }

    long long DayEleven::bothParts(const int iterations) const {
        std::unordered_map<long long, long long> stonesMap;
        std::string numStr;
        for (const char ch : fileContents[0]) {
            if (ch == ' ') {
                if (!numStr.empty()) {
                    stonesMap[stoll(numStr)]++;
                    numStr.clear();
                }
            } else {
                numStr += ch;
            }
        }
        if (!numStr.empty()) {
            stonesMap[stoll(numStr)]++;
        }

        for (int i = 0; i < iterations; i++) {
            std::unordered_map<long long, long long> newStonesMap;
            for (const auto& [key, count] : stonesMap) {
                if (key == 0) {
                    newStonesMap[1] += count;
                } else {
                    long long leftPart = key;
                    long long rightPart = 0;
                    long long multiplier = 1;
                    long long temp = key;
                    int numDigits = 0;

                    while (temp > 0) {
                        temp /= 10;
                        numDigits++;
                    }

                    const int halfDigits = numDigits / 2;
                    for (int j = 0; j < halfDigits; j++) {
                        rightPart += (leftPart % 10) * multiplier;
                        leftPart /= 10;
                        multiplier *= 10;
                    }

                    if (numDigits % 2 == 1) {
                        newStonesMap[key * 2024] += count;
                    } else {
                        newStonesMap[leftPart] += count;
                        newStonesMap[rightPart] += count;
                    }
                }
            }
            stonesMap = std::move(newStonesMap);
        }

        return std::accumulate(stonesMap.begin(), stonesMap.end(), 0LL, [](long long sum, const auto& pair) {
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