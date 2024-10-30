//
// Created by Lukas on 8/31/2024.
//

#include "Directory.h"
Directory::Directory(std::string n, int s) {
    name = n;
    size = s;
}

Directory::Directory(std::string n) {
    name = n;
}

std::string Directory::getName() {
    return name;
}

int Directory::getSize() const {
    return size;
}

std::vector<Directory*>* Directory::getContents() {
    return &contents;
}

void Directory::addToContents(Directory* directory) {
    contents.push_back(directory);
}

Directory* Directory::swapToDir(const std::string& directoryName) {
    for(const auto dir : contents) {
        if(dir->getName() == directoryName) {
            return dir;
        }
    }
}


