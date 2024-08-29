//
// Created by Lukas on 8/28/2024.
//

#include "DayTwo.h"

#include <map>

#include "../../utils.h"

DayTwo::DayTwo(const std::string &fileName) {
    fileContents = utils::readFile(fileName, 2);
}

int DayTwo::partOne() const {
    std::map<char, char> valueMap;
    valueMap.emplace('A', 'R');
    valueMap.emplace('B', 'P');
    valueMap.emplace('C', 'S');
    valueMap.emplace('X', 'R');
    valueMap.emplace('Y', 'P');
    valueMap.emplace('Z', 'S');

    std::map<char, int> pointsMap;
    pointsMap.emplace('R', 1);
    pointsMap.emplace('P', 2);
    pointsMap.emplace('S', 3);

    int score = 0;
    for(std::string line : fileContents) {
        const char opponentPick = valueMap.at(line.at(0));
        char selfPick = valueMap.at(line.at(2));
        const int selfPoints = pointsMap.at(selfPick);

        if(selfPick == 'R' && opponentPick == 'S' ||
            selfPick == 'P' && opponentPick == 'R' ||
            selfPick == 'S' && opponentPick == 'P') {
            score += 6;
        }
        if(selfPick == opponentPick) {
            score += 3;
        }
        score += selfPoints;
    }
    return score;
}

int DayTwo::partTwo() const {
    std::map<char, char> valueMap;
    valueMap.emplace('A', 'R');
    valueMap.emplace('B', 'P');
    valueMap.emplace('C', 'S');
    valueMap.emplace('X', 'R');
    valueMap.emplace('Y', 'P');
    valueMap.emplace('Z', 'S');

    std::map<char, int> pointsMap;
    pointsMap.emplace('R', 1);
    pointsMap.emplace('P', 2);
    pointsMap.emplace('S', 3);

    // X = lose
    // Y = draw
    // Z = win
    int score = 0;
    for(std::string line : fileContents) {
        const char opponentPick = valueMap.at(line.at(0));
        char selfPick = valueMap.at(line.at(2));
        const int selfPoints = pointsMap.at(selfPick);

        switch(selfPick) {
            case 'R':
                switch(opponentPick) {
                    case 'R':
                        score += 3;
                        break;
                    case 'P':
                        score += 1;
                        break;
                    case 'S':
                        score += 2;
                        break;
                }
                break;
            case 'P':
                score += 3;
                switch(opponentPick) {
                    case 'R':
                        score += 1;
                    break;
                    case 'P':
                        score += 2;
                    break;
                    case 'S':
                        score += 3;
                    break;
                }
            break;
            case 'S':
                score += 6;
                switch(opponentPick) {
                    case 'R':
                        score += 2;
                    break;
                    case 'P':
                        score += 3;
                    break;
                    case 'S':
                        score += 1;
                    break;
                }
            break;
        }
    }
    return score;
}

