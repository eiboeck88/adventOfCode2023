//
// Created by aeiboeck on 18.12.2023.
//

#ifndef ADVENT1_DAY5PART2_H
#define ADVENT1_DAY5PART2_H
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

class day5Part2 {
public:

    void dataFeeder();
    std::vector<long long> extractSeedData(std::string rawSeedData);
//    long long calculateSeedMap(std::vector <std::vector<long long>> seedMapRange, long long seedData);
//    long long findSmallestLocation(std::vector<long long> seedData);
//    std::vector<long long> convertSeedDataIntoRanges(std::vector<long long> seedData);
};


#endif //ADVENT1_DAY5PART2_H
