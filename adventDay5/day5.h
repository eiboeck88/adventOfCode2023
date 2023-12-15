//
// Created by aeiboeck on 15.12.2023.
//

#ifndef ADVENT1_DAY5_H
#define ADVENT1_DAY5_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <regex>



class day5 {
public:
    void dataFeeder();
    std::vector<std::vector<int>> seperateData(std::vector<std::string> data);
    //std::vector<std::vector<int>> calculateRanges(std::vector<std::vector<int>> data);
    int getCorrosPonding(int seed, std::vector<std::vector<int>> data);
};


#endif //ADVENT1_DAY5_H
