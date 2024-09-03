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
    std::vector<Directory> contents;

public:
    Directory(std::string name, int size);
    explicit Directory(std::string name);

    std::string getName();
    int getSize();
    std::vector<Directory>* getContents();

    void addToContents(Directory);
};



#endif //DIRECTORY_H
