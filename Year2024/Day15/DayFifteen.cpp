//
// Created by Lukas on 12/9/2024.
//

#include "DayFifteen.h"

#include "../../Utils/utils.h"
#include <string>
#include <unordered_set>

namespace Year2024 {
    DayFifteen::DayFifteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 15, isSample);
    }

    int DayFifteen::partOne() const {
        std::vector<std::vector<char>> warehouse;
        std::vector<int> instructions;
        int robotRow = 0, robotCol = 0;

        std::string box;
        bool isBox = true;
        for (const auto& line : fileContents) {
            if (line.empty()) {
                isBox = false;
                continue;
            }
            if (isBox) {
                std::vector warehouseRow(line.begin(), line.end());
                warehouse.push_back(warehouseRow);
                for (int c = 0; c < line.size(); c++) {
                    if (line[c] == '@') {
                        robotRow = warehouse.size() - 1;
                        robotCol = c;
                    }
                }
            } else {
                for (const char ch : line) {
                    switch (ch) {
                        case '^':
                            instructions.push_back(0);
                        break;
                        case '>':
                            instructions.push_back(1);
                        break;
                        case 'v':
                            instructions.push_back(2);
                        break;
                        case '<':
                            instructions.push_back(3);
                        break;
                    }
                }
            }
        }

        constexpr int dRow[] = {-1, 0, 1, 0};
        constexpr int dCol[] = {0, 1, 0, -1};
        for (const int instr : instructions) {
            const int newRow = robotRow + dRow[instr];
            const int newCol = robotCol + dCol[instr];

            if (newRow < 0 || newRow >= warehouse.size() || newCol < 0 || newCol >= warehouse[0].size()) {
                continue;
            }
            if (warehouse[newRow][newCol] == '.') {
                std::swap(warehouse[robotRow][robotCol], warehouse[newRow][newCol]);
                robotRow = newRow;
                robotCol = newCol;
                continue;
            }
            if (warehouse[newRow][newCol] == '#') {
                continue;
            }

            int boxNewRow = newRow;
            int boxNewCol = newCol;
            while (warehouse[boxNewRow][boxNewCol] == 'O') {
                boxNewRow += dRow[instr];
                boxNewCol += dCol[instr];
                if (boxNewRow < 0 || boxNewRow >= warehouse.size() ||
                    boxNewCol < 0 || boxNewCol >= warehouse[0].size()||
                    warehouse[boxNewRow][boxNewCol] == '#') {
                    break;
                }
            }

            if (warehouse[boxNewRow][boxNewCol] == '#') {
                continue;
            }

            warehouse[boxNewRow][boxNewCol] = 'O';
            warehouse[newRow][newCol] = '@';
            warehouse[robotRow][robotCol] = '.';
            robotRow = newRow;
            robotCol = newCol;
        }

        int sumGPS = 0;
        for (int r = 0; r < warehouse.size(); ++r) {
            for (int c = 0; c < warehouse[r].size(); ++c) {
                if (warehouse[r][c] == 'O') {
                    sumGPS += 100 * r + c;
                }
            }
        }

        return sumGPS;
    }

    int DayFifteen::partTwo() const {
        std::vector<std::vector<char>> warehouse;
        std::vector<int> instructions;
        int robotRow = 0;
        int robotCol = 0;

        std::string box;
        bool isBox = true;
        for (const auto& line : fileContents) {
            if (line.empty()) {
                isBox = false;
                continue;
            }
            if (isBox) {
                std::vector<char> warehouseRow;
                for (int c = 0; c < line.size(); c++) {
                    const char cell = line[c];
                    if (cell == '@') {
                        robotRow = warehouse.size();
                        robotCol = 2 * c;
                    }
                    if (cell == '#') {
                        warehouseRow.push_back('#');
                        warehouseRow.push_back('#');
                    } else if (cell == 'O') {
                        warehouseRow.push_back('[');
                        warehouseRow.push_back(']');
                    } else if (cell == '.') {
                        warehouseRow.push_back('.');
                        warehouseRow.push_back('.');
                    } else if (cell == '@') {
                        warehouseRow.push_back('@');
                        warehouseRow.push_back('.');
                    }
                }
                warehouse.push_back(warehouseRow);
            } else {
                for (const char ch : line) {
                    switch (ch) {
                        case '^':
                            instructions.push_back(0);
                        break;
                        case '>':
                            instructions.push_back(1);
                        break;
                        case 'v':
                            instructions.push_back(2);
                        break;
                        case '<':
                            instructions.push_back(3);
                        break;
                    }
                }
            }
        }

        constexpr int dRow[] = {-1, 0, 1, 0};
        constexpr int dCol[] = {0, 1, 0, -1};
        for (const int instr : instructions) {
            const int newRow = robotRow + dRow[instr];
            const int newCol = robotCol + dCol[instr];

            if (newRow < 0 || newRow >= warehouse.size() || newCol < 0 || newCol >= warehouse[0].size()) {
                continue;
            }
            if (warehouse[newRow][newCol] == '.') {
                std::swap(warehouse[robotRow][robotCol], warehouse[newRow][newCol]);
                robotRow = newRow;
                robotCol = newCol;
                continue;
            }
            if (warehouse[newRow][newCol] == '#') {
                continue;
            }

            if (dRow[instr] == 0) {
                int tx = newRow;
                int ty = newCol;
                int dist = 0;
                while (warehouse[tx][ty] == '[' || warehouse[tx][ty] == ']') {
                    dist++;
                    tx += dRow[instr];
                    ty += dCol[instr];
                }

                if (warehouse[tx][ty] == '#') {
                    continue;
                }

                for (int i = 0; i < dist; i++) {
                    warehouse[tx][ty] = warehouse[tx - dRow[instr]][ty - dCol[instr]];
                    tx -= dRow[instr];
                    ty -= dCol[instr];
                }

                warehouse[newRow][newCol] = '@';
                warehouse[robotRow][robotCol] = '.';
                robotRow = newRow;
                robotCol = newCol;
                continue;
            }

            std::vector<std::unordered_set<std::pair<int, int>, pairHash>> toPush = {{std::make_pair(robotRow, robotCol)}};
            bool noWall = true, allEmpty = false;

            while (noWall && !allEmpty) {
                std::unordered_set<std::pair<int, int>, pairHash> nextPush;
                allEmpty = true;
                for (const auto& [cx, cy] : toPush.back()) {
                    if (warehouse[cx][cy] == '.') {
                        continue;
                    }
                    int tx = cx + dRow[instr], ty = cy + dCol[instr];
                    if (warehouse[tx][ty] != '.') {
                        allEmpty = false;
                    }

                    nextPush.insert(std::make_pair(tx, ty));

                    if (warehouse[tx][ty] == '#') {
                        noWall = false;
                        break;
                    }

                    if (warehouse[tx][ty] == '[') {
                        nextPush.insert(std::make_pair(tx, ty + 1));
                    } else if (warehouse[tx][ty] == ']') {
                        nextPush.insert(std::make_pair(tx, ty - 1));
                    }
                }
                toPush.push_back(nextPush);
            }

            if (!noWall) {
                continue;
            }

            for (int i = toPush.size() - 1; i > 0; i--) {
                for (const auto& [cx, cy] : toPush[i]) {
                    int fx = cx - dRow[instr], fy = cy - dCol[instr];
                    if (toPush[i - 1].contains(std::make_pair(fx, fy))) {
                        warehouse[cx][cy] = warehouse[fx][fy];
                    } else {
                        warehouse[cx][cy] = '.';
                    }
                }
            }

            warehouse[robotRow][robotCol] = '.';
            robotRow = newRow;
            robotCol = newCol;
        }

        int sumGPS = 0;
        for (int r = 0; r < warehouse.size(); r++) {
            for (int c = 0; c < warehouse[r].size(); c++) {
                if (warehouse[r][c] == '[') {
                    sumGPS += 100 * r + c;
                }
            }
        }

        return sumGPS;
    }

} // Year2024