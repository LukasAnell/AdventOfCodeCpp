//
// Created by Lukas on 12/9/2024.
//

#include "DayTwenty.h"

#include <queue>

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayTwenty::DayTwenty(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 20, isSample);
    }

    int DayTwenty::bfs(const std::vector<std::string>& map, const int startX, const int startY, const int endX, const int endY) {
        const int rows = map.size();
        const int cols = map[0].size();
        std::queue<State> q;
        q.push({startX, startY, 0, 0});
        std::vector visited(rows, std::vector(cols, std::vector(2, false)));
        visited[startX][startY][0] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            const State current = q.front();
            q.pop();

            if (current.x == endX && current.y == endY) {
                return current.time;
            }

            for (const auto& dir : directions) {
                const int newX = current.x + dir[0];
                const int newY = current.y + dir[1];

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    if (map[newX][newY] == '.' || map[newX][newY] == 'E') {
                        if (!visited[newX][newY][current.cheatUsed]) {
                            visited[newX][newY][current.cheatUsed] = true;
                            q.push({newX, newY, current.time + 1, current.cheatUsed});
                        }
                    } else if (map[newX][newY] == '#' && current.cheatUsed == 0) {
                        for (int cheatTime = 1; cheatTime <= 2; cheatTime++) {
                            const int cheatX = newX + dir[0] * (cheatTime - 1);
                            const int cheatY = newY + dir[1] * (cheatTime - 1);
                            if (cheatX >= 0 && cheatX < rows && cheatY >= 0 && cheatY < cols && (map[cheatX][cheatY] == '.' || map[cheatX][cheatY] == 'E')) {
                                if (!visited[cheatX][cheatY][1]) {
                                    visited[cheatX][cheatY][1] = true;
                                    q.push({cheatX, cheatY, current.time + cheatTime, 1});
                                }
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }

    int DayTwenty::partOne() const {
        std::vector<std::string> map;
        for (std::string line :fileContents) {
            map.push_back(line);
        }

        int startX;
        int startY;
        int endX;
        int endY;
        for (int i = 0; i < map.size(); i++) {
            for (int j = 0; j < map[0].size(); j++) {
                if (map[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (map[i][j] == 'E') {
                    endX = i;
                    endY = j;
                }
            }
        }
        return bfs(map, startX, startY, endX, endY);
    }
} // Year2024