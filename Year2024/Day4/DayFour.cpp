//
// Created by Lukas on 12/4/2024.
//

#include "DayFour.h"

#include "../../utils.h"
#include <regex>

namespace Year2024 {
    DayFour::DayFour(const std::string& fileName) {
        fileContents = utils::readFile(fileName, 4);
    }

    int DayFour::partOne() const {
        int count = 0;
        std::vector<std::string> rows;
        std::vector<std::string> cols;
        std::vector<std::string> diags1;
        std::vector<std::string> diags2;

        for (int i = 0; i < fileContents.size(); i++) {
            std::string row;
            std::string col;
            for (int j = 0; j < fileContents[0].size(); j++) {
                row += fileContents[i][j];
                col += fileContents[j][i];
            }
            rows.emplace_back(row);
            cols.emplace_back(col);
        }

        for (int i = 0; i < fileContents.size() * 2 - 1; i++) {
            std::string diag1;
            for (int j = 0; j < fileContents.size(); j++) {
                int k = i - j;
                if (k >= 0 && k < fileContents.size()) {
                    diag1 += fileContents[j][k];
                }
            }
            if (!diag1.empty()) diags1.emplace_back(diag1);
        }

        for (int i = 0; i < fileContents.size() * 2 - 1; i++) {
            std::string diag2;
            for (int j = 0; j < fileContents.size(); j++) {
                int k = j + i - (fileContents.size() - 1);
                if (k >= 0 && k < fileContents.size()) {
                    diag2 += fileContents[j][k];
                }
            }
            if (!diag2.empty()) diags2.emplace_back(diag2);
        }

        const std::regex xmasRgx(R"(XMAS)");
        const std::regex samxRgx(R"(SAMX)");
        std::smatch matches;
        auto countMatches = [&](const std::vector<std::string>& lines) {
            for (const std::string& line : lines) {
                auto xmasSearchStart(line.begin());
                while (std::regex_search(xmasSearchStart, line.cend(), matches, xmasRgx)) {
                    count++;
                    xmasSearchStart = matches[0].second;
                }
                auto samxSearchStart(line.begin());
                while (std::regex_search(samxSearchStart, line.cend(), matches, samxRgx)) {
                    count++;
                    samxSearchStart = matches[0].second;
                }
            }
        };

        countMatches(rows);
        countMatches(cols);
        countMatches(diags1);
        countMatches(diags2);

        return count;
    }

    int DayFour::partTwo() const {
        int count = 0;

        const std::regex masRgx(R"(MAS)");
        const std::regex samRgx(R"(SAM)");
        std::smatch matches;
        for (int r = 1; r < fileContents.size() - 1; r++) {
            for (int c = 1; c < fileContents[0].size() - 1; c++) {
                if (fileContents[r][c] == 'A') {
                    std::string firstDiag = std::string(1, fileContents[r - 1][c - 1]) + fileContents[r][c] + fileContents[r + 1][c + 1];
                    std::string secondDiag = std::string(1, fileContents[r + 1][c - 1]) + fileContents[r][c] + fileContents[r - 1][c + 1];
                    if ((firstDiag == "MAS" || firstDiag == "SAM") && (secondDiag == "MAS" || secondDiag == "SAM")) {
                        count++;
                    }
                }
            }
        }

        return count;
    }

}