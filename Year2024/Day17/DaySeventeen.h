//
// Created by Lukas on 12/9/2024.
//

#ifndef YEAR2024_DAYSEVENTEEN_H
#define YEAR2024_DAYSEVENTEEN_H
#include <string>
#include <vector>

namespace Year2024 {
    class DaySeventeen {
    public:
        std::vector<std::string> fileContents;
        struct Registers {
            long long a, b, c;
            int ip;
        };

        enum class Opcode {
            adv = 0,
            bxl = 1,
            bst = 2,
            jnz = 3,
            bxc = 4,
            oot = 5,
            bdv = 6,
            cdv = 7
        };

        struct Op {
            Opcode opcode;
            int operand;
        };

        explicit DaySeventeen(const std::string& fileName, bool isSample);
        [[nodiscard]] std::string partOne() const;
        [[nodiscard]] static Registers applyInstruction(const Registers& regs, const Op& op, std::vector<int>& output);
        [[nodiscard]] static std::vector<int> runProgram(Registers regs, const std::vector<int>& program, long long overrideA = -1, bool breakOnFirstOutput = false);
        [[nodiscard]] static std::vector<long long> findBits(long long a, int output, const std::vector<int>& program);
        [[nodiscard]] static long long findInitialA(const std::vector<int>& program);
        [[nodiscard]] static long long partTwo();
    };
} // Year2024

#endif //YEAR2024_DAYSEVENTEEN_H
