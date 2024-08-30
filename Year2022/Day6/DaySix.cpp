//
// Created by Lukas on 8/30/2024.
//

#include "DaySix.h"
#include "../../utils.h"

DaySix::DaySix(const std::string &fileName) {
    fileContents = utils::readFile(fileName, 6);
}

int DaySix::bothParts(int distinctAmount) const {
    const std::string line = fileContents[0];
    for(int i = 0; i < line.length() - distinctAmount; i++) {
        std::string currentSequence = line.substr(i, distinctAmount);
        bool foundDuplicate = false;
        for(int j = 0; j < currentSequence.length(); j++) {
            for(int k = j + 1; k < currentSequence.length(); k++) {
                if(currentSequence[j] == currentSequence[k]) {
                    foundDuplicate = true;
                    break;
                }
            }
            if(foundDuplicate) {
                break;
            }
        }
        if(!foundDuplicate) {
            return i + distinctAmount;
        }
    }
}
