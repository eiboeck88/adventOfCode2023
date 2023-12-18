//
// Created by alex on 17.12.23.
//

#ifndef ADVENT_DAY5_H
#define ADVENT_DAY5_H
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class day5 {
public:
    std::vector<int> findSeedData(std::string data);
    void day5Run();
    void eraseLines(int currentLine, std::vector<std::string> &data);
    std::vector<int> mapSeed(std::vector<int> seedData, std::vector<std::string> &data);
};


#endif //ADVENT_DAY5_H
