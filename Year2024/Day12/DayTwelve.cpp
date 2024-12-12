//
// Created by Lukas on 12/9/2024.
//

#include "DayTwelve.h"

#include <set>

#include "../../Utils/utils.h"
#include <string>
#include <unordered_map>
#include <variant>

namespace Year2024 {
    DayTwelve::DayTwelve(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 12, isSample);
    }

    void DayTwelve::dfs1(int r, int c, char currentChar, std::set<std::pair<int, int> > &visited, int &area, int &perimeter) const {
        const int rows = fileContents.size();
        const int cols = fileContents[0].size();
        const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        visited.emplace(r, c);
        area++;

        for (const auto& [dr, dc] : directions) {
            int newRow = r + dr;
            int newCol = c + dc;
            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || fileContents[newRow][newCol] != currentChar) {
                perimeter++;
            } else if (!visited.contains({newRow, newCol})) {
                dfs1(newRow, newCol, currentChar, visited, area, perimeter);
            }
        }
    }


    int DayTwelve::partOne() const {
        std::unordered_map<std::string, int> totalPrice;
        std::set<std::pair<int, int>> visited;
        for (int r = 0; r < fileContents.size(); r++) {
            for (int c = 0; c < fileContents[0].size(); c++) {
                const char currentChar = fileContents[r][c];
                if (!visited.contains({r, c})) {
                    int area = 0;
                    int perimeter = 0;
                    dfs1(r, c, currentChar, visited, area, perimeter);
                    totalPrice[std::string{currentChar}] += area * perimeter;
                }
            }
        }

        int sum = 0;
        for (const auto& [key, price] : totalPrice) {
            sum += price;
        }
        return sum;
    }

    int DayTwelve::partTwo() const {

    }
} // Year2024