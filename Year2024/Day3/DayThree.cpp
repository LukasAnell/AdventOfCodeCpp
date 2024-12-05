//
// Created by Lukas on 12/4/2024.
//

#include "DayThree.h"

#include "../../utils.h"
#include <regex>

namespace Year2024 {
    DayThree::DayThree(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 3);
    }

    int DayThree::partOne() const {
        int total = 0;
        const std::regex rgx(R"(mul\(([0-9]{1,3}),([0-9]{1,3})\))");
        std::smatch matches;
        for (const std::string& row : fileContents) {
            auto searchStart(row.begin());
            while(std::regex_search(searchStart, row.cend(), matches, rgx)) {
                total += stoi(matches[1].str()) * stoi(matches[2].str());
                searchStart = matches.suffix().first;
            }
        }
        return total;
    }

    int DayThree::partTwo() const {
        int total = 0;
        const std::regex mulExpr(R"(^mul\(([0-9]{1,3}),([0-9]{1,3})\))");
        const std::regex doExpr(R"(^do\(\))");
        const std::regex dontExpr(R"(^don't\(\))");
        std::smatch matches;
        bool enabled = true;
        for (const std::string& row : fileContents) {
            for(int i = 0; i < row.size(); i++) {
                std::string newRow = row.substr(i);
                if(std::regex_search(newRow, matches, doExpr)) {
                    enabled = true;
                }
                if(std::regex_search(newRow, matches, dontExpr)) {
                    enabled = false;
                }
                if(enabled && std::regex_search(newRow, matches, mulExpr)) {
                    total += stoi(matches[1].str()) * stoi(matches[2].str());
                }
            }
        }
        return total;
    }

}