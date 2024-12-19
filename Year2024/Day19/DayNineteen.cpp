//
// Created by Lukas on 12/9/2024.
//

#include "DayNineteen.h"

#include "../../Utils/utils.h"
#include <string>
#include <unordered_set>

namespace Year2024 {
    DayNineteen::DayNineteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 19, isSample);
    }

    int DayNineteen::partOne() const {
        std::vector<std::string> towelPatterns = utils::splitString(fileContents[0], ", ");
        int possibleDesigns = 0;
        for (int i = 2; i < fileContents.size(); i++) {
            std::string design = fileContents[i];
            std::vector dp(design.size() + 1, 0);
            dp[0] = 1;

            for (int j = 0; j < design.size(); j++) {
                if (dp[j] == 0) continue;
                for (const std::string& pattern : towelPatterns) {
                    if (design.substr(j, pattern.size()) == pattern) {
                        dp[j + pattern.size()] = 1;
                    }
                }
            }

            if (dp[design.size()] == 1) {
                possibleDesigns++;
            }
        }
        return possibleDesigns;
    }

    long long DayNineteen::partTwo() const {
        std::vector<std::string> towelPatterns = utils::splitString(fileContents[0], ", ");
        long long totalPermutations = 0;

        for (int i = 2; i < fileContents.size(); i++) {
            std::string design = fileContents[i];
            std::vector<long long> dp(design.size() + 1, 0);
            dp[0] = 1;

            for (int j = 0; j < design.size(); j++) {
                if (dp[j] == 0) continue;
                for (const std::string& pattern : towelPatterns) {
                    if (design.substr(j, pattern.size()) == pattern) {
                        dp[j + pattern.size()] += dp[j];
                    }
                }
            }

            totalPermutations += dp[design.size()];
        }

        return totalPermutations;
    }

} // Year2024