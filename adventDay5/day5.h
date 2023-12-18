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

    void dataFeeder();
    std::vector<long long> calculateSeedMap(std::vector<std::vector<long long>> seedMapRange, std::vector<long long> seedData);
    std::vector<long long> extractSeedData(std::string rawSeedData);
    long long findSmallestLocation(std::vector<long long> seedData);
};


#endif //ADVENT_DAY5_H
