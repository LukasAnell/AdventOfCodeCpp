//
// Created by Lukas on 12/5/2024.
//

#include "DayNine.h"

#include "../../Utils/utils.h"
#include <string>

namespace Year2024 {
    DayNine::DayNine(const std::string& fileName, const bool isSample) {
        fileContents = utils::readFile(fileName, 2024, 9, isSample);
    }

    long long DayNine::partOne() const {
        std::vector<int> files;
        std::vector<int> freeSpace;
        std::vector<int> diskMap;

        for (int i = 0; i < fileContents[0].size(); i++) {
            int length = fileContents[0][i] - '0';
            if (i % 2 == 0) {
                files.push_back(length);
            } else {
                freeSpace.push_back(length);
            }
        }

        int fileId = 0;
        for (int i = 0; i < files.size(); i++) {
            for (int j = 0; j < files[i]; j++) {
                diskMap.push_back(fileId);
            }
            if (i < freeSpace.size()) {
                for (int j = 0; j < freeSpace[i]; j++) {
                    diskMap.push_back(-1);
                }
            }
            fileId++;
        }

        for (int i = 0; i < diskMap.size(); i++) {
            if (diskMap[i] == -1) {
                while (diskMap[diskMap.size() - 1] == -1) {
                    diskMap.erase(diskMap.end());
                }
                diskMap[i] = diskMap[diskMap.size() - 1];
                diskMap.erase(diskMap.end());
                i--;
            }
        }

        long long checksum = 0;
        for (int i = 0; i < diskMap.size(); i++) {
            if (diskMap[i] != -1) {
                checksum += static_cast<long long>(i) * diskMap[i];
            }
        }

        return checksum;
    }

    long long DayNine::partTwo() const {
        std::vector<int> files;
        std::vector<int> freeSpace;
        std::vector<std::pair<int, int>> diskMap;
        std::vector<std::pair<int, int>> filesMap;

        for (int i = 0; i < fileContents[0].size(); i++) {
            int length = fileContents[0][i] - '0';
            if (i % 2 == 0) {
                files.push_back(length);
            } else {
                freeSpace.push_back(length);
            }
        }

        int fileId = 0;
        for (int i = 0; i < files.size(); i++) {
            diskMap.emplace_back(fileId, files[i]);
            filesMap.emplace_back(fileId, files[i]);
            if (i < freeSpace.size() && freeSpace[i] != 0) {
                diskMap.emplace_back(-1, freeSpace[i]);
            }
            fileId++;
        }

        for (int currentId = filesMap.size() - 1; currentId >= 0; currentId--) {
            int currentLength = filesMap[currentId].second;
            int toReplaceIndex = 0;
            for (int j = 0; j < diskMap.size(); j++) {
                if (filesMap[currentId].first == diskMap[j].first) {
                    toReplaceIndex = j;
                    break;
                }
            }
            for (int i = 0; i < diskMap.size() && i < toReplaceIndex; i++) {
                if (diskMap[i].first == -1) {
                    int freeLength = diskMap[i].second;
                    if (freeLength >= currentLength) {
                        diskMap[toReplaceIndex] = std::pair(-1, currentLength);
                        diskMap[i] = std::pair(filesMap[currentId].first, currentLength);
                        if (freeLength - currentLength > 0) {
                            diskMap.insert(diskMap.begin() + i + 1, std::pair(-1, freeLength - currentLength));
                        }
                        break;
                    }
                }
            }
        }

        long long checksum = 0;
        int iterator = 0;
        for (auto &[first, second] : diskMap) {
            for (int j = 0; j < second; j++) {
                if (first != -1) {
                    checksum += static_cast<long long>(iterator) * first;
                }
                iterator++;
            }
        }

        return checksum;
    }

}