//
// Created by Lukas on 12/9/2024.
//

#include "DaySeventeen.h"

#include <algorithm>
#include <cmath>
#include <iostream>

#include "../../Utils/utils.h"
#include <string>
#include <unordered_map>

namespace Year2024 {
    DaySeventeen::DaySeventeen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 17, isSample);
    }

    std::string DaySeventeen::partOne() const {
        std::unordered_map<char, int> registers = {{'A', 0}, {'B', 0}, {'C', 0}};
        std::vector<int> instructions;
        for (std::string line : fileContents) {
            if (line.empty()) {
                continue;
            }
            std::vector<std::string> parts = utils::splitString(line, " ");
            std::string first = parts[0];
            std::string second = parts[1];
            std::string third;
            if (parts.size() >= 3) {
                third = parts[2];
            }

            if (first == "Register") {
                if (second == "A:") {
                    registers['A'] = stoi(third);
                } else if (second == "B:") {
                    registers['B'] = stoi(third);
                } else if (second == "C:") {
                    registers['C'] = stoi(third);
                }
            } else if (first == "Program:") {
                std::vector<std::string> nums = utils::splitString(second, ",");
                for (std::string num : nums) {
                    instructions.push_back(stoi(num));
                }
            }
        }

        std::string output = "";
        int index = 0;
        while (index < instructions.size()) {
            int opcode = instructions[index];
            int operand = instructions[index + 1];
            int comboOperand = 0;
            switch (operand) {
                case 0: case 1: case 2: case 3:
                    comboOperand = operand;
                    break;
                case 4:
                    comboOperand = registers['A'];
                    break;
                case 5:
                    comboOperand = registers['B'];
                    break;
                case 6:
                    comboOperand = registers['C'];
                    break;
                case 7:
                    // reserved
                    break;
            }
            switch (opcode) {
                case 0:
                    registers['A'] = registers['A'] / static_cast<int>(std::pow(2, comboOperand));
                    break;
                case 1:
                    registers['B'] = registers['B'] ^ operand;
                    break;
                case 2:
                    registers['B'] = comboOperand % 8;
                    break;
                case 3:
                    if (registers['A'] != 0) {
                        index = operand;
                        continue;
                    }
                    break;
                case 4:
                    registers['B'] = registers['B'] ^ registers['C'];
                    break;
                case 5:
                    output += std::to_string(comboOperand % 8) + ",";
                break;
                case 6:
                    registers['B'] = registers['A'] / static_cast<int>(std::pow(2, comboOperand));
                    break;
                case 7:
                    registers['C'] = registers['A'] / static_cast<int>(std::pow(2, comboOperand));
                    break;
            }

            index += 2;
        }

        std::string newOut = "";
        for (int i = 0; i < output.size() - 1; i++) {
                newOut += output[i];
        }
        return newOut;
    }

    DaySeventeen::Registers DaySeventeen::applyInstruction(const Registers& regs, const Op& op, std::vector<int>& output) {
        const std::vector<long long> combo = {0, 1, 2, 3, regs.a, regs.b, regs.c};
        Registers newRegs = regs;
        switch (op.opcode) {
            case Opcode::adv:
                newRegs.a = regs.a / static_cast<int>(std::pow(2, combo[op.operand]));
                newRegs.ip += 2;
                break;
            case Opcode::bxl:
                newRegs.b = regs.b ^ op.operand;
                newRegs.ip += 2;
                break;
            case Opcode::bst:
                newRegs.b = combo[op.operand] % 8;
                newRegs.ip += 2;
                break;
            case Opcode::jnz:
                if (regs.a != 0) {
                    newRegs.ip = op.operand;
                } else {
                    newRegs.ip += 2;
                }
                break;
            case Opcode::bxc:
                newRegs.b = regs.b ^ regs.c;
                newRegs.ip += 2;
                break;
            case Opcode::oot:
                output.push_back(combo[op.operand] % 8);
                newRegs.ip += 2;
                break;
            case Opcode::bdv:
                newRegs.b = regs.a / static_cast<int>(std::pow(2, combo[op.operand]));
                newRegs.ip += 2;
                break;
            case Opcode::cdv:
                newRegs.c = regs.a / static_cast<int>(std::pow(2, combo[op.operand]));
                newRegs.ip += 2;
                break;
        }
        return newRegs;
    }

    std::vector<int> DaySeventeen::runProgram(Registers regs, const std::vector<int>& program, const long long overrideA, const bool breakOnFirstOutput) {
        if (overrideA != -1) {
            regs.a = overrideA;
        }
        std::vector<int> output;
        while (regs.ip < program.size() - 1) {
            int op = program[regs.ip];
            const int operand = program[regs.ip + 1];
            regs = applyInstruction(regs, {static_cast<Opcode>(op), operand}, output);
            if (breakOnFirstOutput && !output.empty()) {
                return output;
            }
        }
        return output;
    }

    std::vector<long long> DaySeventeen::findBits(const long long a, const int output, const std::vector<int>& program) {
        std::vector<long long> variants;
        for (int bits = 0; bits < 8; bits++) {
            long long answ = (a << 3) + bits;
            auto out = runProgram({answ, 0, 0, 0}, program, answ, true);
            if (out.size() == 1 && out[0] == output) {
                variants.push_back(answ);
            }
        }
        return variants;
    }

    long long DaySeventeen::findInitialA(const std::vector<int>& program) {
        std::vector<long long> candidates = {0};
        for (auto it = program.rbegin(); it != program.rend(); ++it) {
            std::vector<long long> newCandidates;
            for (const long long a : candidates) {
                auto bits = findBits(a, *it, program);
                newCandidates.insert(newCandidates.end(), bits.begin(), bits.end());
            }
            candidates = newCandidates;
        }
        return *std::ranges::min_element(candidates);
    }

    long long DaySeventeen::partTwo() {
        const std::vector program = {2, 4, 1, 3, 7, 5, 1, 5, 0, 3, 4, 1, 5, 5, 3, 0};
        return findInitialA(program);
    }
} // Year2024