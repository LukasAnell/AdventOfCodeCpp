//
// Created by Lukas on 12/5/2024.
//

#ifndef YEAR2024_DAYSEVEN_H
#define YEAR2024_DAYSEVEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySeven {
    public:
        std::vector<std::string> fileContents;

        explicit DaySeven(const std::string& fileName, bool isSample);
        [[nodiscard]] static bool part1EvaluateExpression(const std::vector<long long>& numbers, const std::vector<char>& operators, long long target);
        static void part1GenerateOperators(std::vector<char>& operators, size_t index, const std::vector<long long>& numbers, long long target, bool& found);
        [[nodiscard]] long long partOne() const;
        [[nodiscard]] static bool part2EvaluateExpression(const std::vector<long long>& numbers, const std::vector<std::string>& operators, long long target);
        static void part2GenerateOperators(std::vector<std::string>& operators, size_t index, const std::vector<long long>& numbers, long long target, bool& found);
        [[nodiscard]] long long partTwo() const;
    };
}

#endif //YEAR2024_DAYSEVEN_H
