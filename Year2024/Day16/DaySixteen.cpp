//
// Created by Lukas on 12/9/2024.
//

#include "DaySixteen.h"

#include <iostream>
#include <queue>

#include "../../Utils/utils.h"
#include <string>
#include <unordered_set>

namespace Year2024 {
    DaySixteen::DaySixteen(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 16, isSample);
    }

    void DaySixteen::move(const std::vector<std::vector<char>>& maze, Reindeer& rein, const int direction) {
        switch (direction) {
            case 0: // up
                if (rein.y > 0 && maze[rein.y - 1][rein.x] != '#') {
                    rein.y--;
                }
            break;
            case 1: // right
                if (rein.x < maze[0].size() - 1 && maze[rein.y][rein.x + 1] != '#') {
                    rein.x++;
                }
            break;
            case 2: // down
                if (rein.y < maze.size() - 1 && maze[rein.y + 1][rein.x] != '#') {
                    rein.y++;
                }
            break;
            case 3: // left
                if (rein.x > 0 && maze[rein.y][rein.x - 1] != '#') {
                    rein.x--;
                }
            break;
        }
    }

    int DaySixteen::partOne() const {
        std::vector<std::vector<char>> maze;
        Reindeer rein;
        End end;
        for (int r = 0; r < fileContents.size(); r++) {
            std::string line = fileContents[r];
            std::vector<char> mazeRow;
            for (int c = 0; c < line.size(); c++) {
                char tile = line[c];
                if (tile == 'S') {
                    rein = Reindeer{c, r, 1};
                    mazeRow.push_back('.');
                } else if (tile == 'E') {
                    end = End{c, r};
                    mazeRow.push_back('.');
                } else {
                    mazeRow.push_back(tile);
                }
            }
            maze.push_back(mazeRow);
        }

        std::priority_queue<State, std::vector<State>, std::greater<>> pq;
        std::unordered_set<std::tuple<int, int, int>, TupleHash> visited;
        pq.push({rein.x, rein.y, rein.facing, 0});
        visited.insert({rein.x, rein.y, rein.facing});

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.x == end.x && current.y == end.y) {
                return current.score;
            }

            Reindeer nextRein = {current.x, current.y, current.facing};
            move(maze, nextRein, current.facing);
            if (!visited.contains({nextRein.x, nextRein.y, nextRein.facing})) {
                pq.push({nextRein.x, nextRein.y, nextRein.facing, current.score + 1});
                visited.insert({nextRein.x, nextRein.y, nextRein.facing});
            }

            int newFacing = (current.facing + 1) % 4;
            if (!visited.contains({current.x, current.y, newFacing})) {
                pq.push({current.x, current.y, newFacing, current.score + 1000});
                visited.insert({current.x, current.y, newFacing});
            }

            newFacing = (current.facing + 3) % 4;
            if (!visited.contains({current.x, current.y, newFacing})) {
                pq.push({current.x, current.y, newFacing, current.score + 1000});
                visited.insert({current.x, current.y, newFacing});
            }
        }

        return -1;
    }

    int DaySixteen::partTwo() const {
        std::vector<std::vector<char>> maze;
        Reindeer rein;
        End end;
        for (int r = 0; r < fileContents.size(); r++) {
            std::string line = fileContents[r];
            std::vector<char> mazeRow;
            for (int c = 0; c < line.size(); c++) {
                char tile = line[c];
                if (tile == 'S') {
                    rein = Reindeer{c, r, 1};
                    mazeRow.push_back('.');
                } else if (tile == 'E') {
                    end = End{c, r};
                    mazeRow.push_back('.');
                } else {
                    mazeRow.push_back(tile);
                }
            }
            maze.push_back(mazeRow);
        }

        std::priority_queue<State, std::vector<State>, std::greater<>> pq;
        std::unordered_set<std::tuple<int, int, int>, TupleHash> visited;
        pq.push({rein.x, rein.y, rein.facing, 0, {{rein.x, rein.y}}});
        visited.insert({rein.x, rein.y, rein.facing});

        std::unordered_set<std::pair<int, int>, pairHash> bestPathTiles;

        while (!pq.empty()) {
            State current = pq.top();
            pq.pop();

            if (current.x == end.x && current.y == end.y) {
                bestPathTiles.insert(current.path.begin(), current.path.end());
                continue;
            }

            Reindeer nextRein = {current.x, current.y, current.facing};
            move(maze, nextRein, current.facing);
            if (!visited.contains({nextRein.x, nextRein.y, nextRein.facing})) {
                auto newPath = current.path;
                newPath.emplace_back(nextRein.x, nextRein.y);
                pq.push({nextRein.x, nextRein.y, nextRein.facing, current.score + 1, newPath});
                visited.insert({nextRein.x, nextRein.y, nextRein.facing});
            }

            int newFacing = (current.facing + 1) % 4;
            if (!visited.contains({current.x, current.y, newFacing})) {
                const auto newPath = current.path;
                pq.push({current.x, current.y, newFacing, current.score + 1000, newPath});
                visited.insert({current.x, current.y, newFacing});
            }

            newFacing = (current.facing + 3) % 4;
            if (!visited.contains({current.x, current.y, newFacing})) {
                const auto newPath = current.path;
                pq.push({current.x, current.y, newFacing, current.score + 1000, newPath});
                visited.insert({current.x, current.y, newFacing});
            }
        }

        return bestPathTiles.size();
    }

} // Year2024