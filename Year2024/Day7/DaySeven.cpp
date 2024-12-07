//
// Created by Lukas on 12/5/2024.
//

#include "DaySeven.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DaySeven::DaySeven(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 7, isSample);
    }

    bool part1EvaluateExpression(const std::vector<long long>& numbers, const std::vector<char>& operators, long long target) {
        long long result = numbers[0];
        for (size_t i = 0; i < operators.size(); ++i) {
            if (operators[i] == '+') {
                result += numbers[i + 1];
            } else if (operators[i] == '*') {
                result *= numbers[i + 1];
            }
        }
        return result == target;
    }

    void part1GenerateOperators(std::vector<char>& operators, size_t index, const std::vector<long long>& numbers, long long target, bool& found) {
        if (index == operators.size()) {
            if (part1EvaluateExpression(numbers, operators, target)) {
                found = true;
            }
            return;
        }
        operators[index] = '+';
        part1GenerateOperators(operators, index + 1, numbers, target, found);
        operators[index] = '*';
        part1GenerateOperators(operators, index + 1, numbers, target, found);
    }

    long long DaySeven::partOne() const {
        long long totalCalibrationResult = 0;
        for (std::string line : fileContents) {
            const long long testValue = stoll(line.substr(0, line.find(':')));
            std::vector<long long> equation;
            for (int i = line.find(':') + 2; i < line.size(); i++) {
                std::string numString;
                for (int j = i; j < line.size(); j++) {
                    if (line[j] == ' ') {
                        break;
                    }
                    numString += line[j];
                }
                if (!numString.empty()) {
                    i += numString.size() - 1;
                    equation.emplace_back(stoll(numString));
                }

            }

            std::vector<char> operators(equation.size() - 1);
            bool found = false;
            part1GenerateOperators(operators, 0, equation, testValue, found);

            if (found) {
                totalCalibrationResult += testValue;
            }
        }
        return totalCalibrationResult;
    }

    bool part2EvaluateExpression(const std::vector<long long>& numbers, const std::vector<std::string>& operators, long long target) {
        long long result = numbers[0];
        for (size_t i = 0; i < operators.size(); ++i) {
            if (operators[i] == "+") {
                result += numbers[i + 1];
            } else if (operators[i] == "*") {
                result *= numbers[i + 1];
            } else if (operators[i] == "||") {
                result = std::stoll(std::to_string(result) + std::to_string(numbers[i + 1]));
            }
        }
        return result == target;
    }

    void part2GenerateOperators(std::vector<std::string>& operators, size_t index, const std::vector<long long>& numbers, long long target, bool& found) {
        if (index == operators.size()) {
            if (part2EvaluateExpression(numbers, operators, target)) {
                found = true;
            }
            return;
        }
        operators[index] = "+";
        part2GenerateOperators(operators, index + 1, numbers, target, found);
        operators[index] = "*";
        part2GenerateOperators(operators, index + 1, numbers, target, found);
        operators[index] = "||";
        part2GenerateOperators(operators, index + 1, numbers, target, found);
    }

    long long DaySeven::partTwo() const {
        long long totalCalibrationResult = 0;
        for (const std::string& line : fileContents) {
            const long long testValue = std::stoll(line.substr(0, line.find(':')));
            std::vector<long long> equation;
            for (int i = line.find(':') + 2; i < line.size(); i++) {
                std::string numString;
                for (int j = i; j < line.size(); j++) {
                    if (line[j] == ' ') {
                        break;
                    }
                    numString += line[j];
                }
                if (!numString.empty()) {
                    i += numString.size() - 1;
                    equation.emplace_back(std::stoll(numString));
                }
            }

            std::vector<std::string> operators(equation.size() - 1);
            bool found = false;
            part2GenerateOperators(operators, 0, equation, testValue, found);

            if (found) {
                totalCalibrationResult += testValue;
            }
        }
        return totalCalibrationResult;
    }
}