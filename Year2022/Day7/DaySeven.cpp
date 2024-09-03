//
// Created by Lukas on 8/30/2024.
//

#include "DaySeven.h"

#include "Directory.h"
#include "../../utils.h"

DaySeven::DaySeven(const std::string &fileName) {
    fileContents = utils::readFile(fileName, 7);
}

int DaySeven::partOne() const {
    /* sample input conclusion
    - / (dir)
        - a (dir)
            - e (dir)
                - i (file, size=584)
            - f (file, size=29116)
            - g (file, size=2557)
            - h.lst (file, size=62596)
        - b.txt (file, size=14848514)
        - c.dat (file, size=8504156)
        - d (dir)
            - j (file, size=4060174)
            - d.log (file, size=8033020)
            - d.ext (file, size=5626152)
            - k (file, size=7214296)
    */

    /*
     * cd {dir} -> go to dir
     * note: ".." means go backwards one dir
     *
     * ls -> list all files/folders in current dir
     * depth of 1, do not enter new dirs while listing
     *
     * identifiers:
     * dir -> indicates a dir
     * {number} indicates a file, of file size {number}
     */

    auto firstDir = Directory("/");
    std::string currentDir = "/";
    std::string prevDir;
    std::vector<Directory> currentContents;
    for(std::string line : fileContents) {
        if(line.at(0) == '$') {
            // is command
            currentContents.clear();
            switch(line.substr(2, 2)) {
                case "cd":
                    // enter target directory
                    const std::string targetDir = line.substr(3, line.length() - 3);
                    if(targetDir == "..") {
                        std::string temp = currentDir;
                        currentDir = prevDir;
                        prevDir = currentDir;
                    } else {
                        prevDir = currentDir;
                        currentDir = targetDir;
                    }
                    // TODO: switch to correct Directory object as well.
                break;

                case "ls":
                    // all lines until next $ are in the current dir
                break;
            }
        } else {
            // is not command
            // this means that current line is listing out an element of the current dir
            if(line.substr(0, 3) == "dir") {
                std::string dirName;
                for(int i = 4; i < line.length() - 4; i++) {
                    dirName += line.at(i);
                }
                currentContents.emplace_back(dirName);
            } else {
                std::string name;
                std::string size;
                for(int i = 0; i < line.length(); i++) {
                    if(isdigit(line.at(i))) {
                        size += line.at(i);
                    } else {
                        name += line.at(i);
                    }
                }
                currentContents.emplace_back(name, stoi(size));
            }
        }
    }
}