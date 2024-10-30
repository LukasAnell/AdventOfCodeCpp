//
// Created by Lukas on 8/31/2024.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <string>
#include <vector>


class Directory {
    std::string name;
    int size = 0;
    std::vector<Directory*> contents;

public:
    Directory(std::string n, int s);
    explicit Directory(std::string n);

    std::string getName();
    int getSize() const;
    std::vector<Directory*>* getContents();

    void addToContents(Directory* directory);
    Directory* swapToDir(const std::string& directoryName);
};



#endif //DIRECTORY_H
