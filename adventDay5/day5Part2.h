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
#include "mapRange.h"
#include <istream>

class day5Part2 {
public:

    void dataFeeder();
    std::vector<long long> extractSeedData(std::string rawSeedData);
    std::vector<std::vector<mapRange>> convertSeedDataIntoRanges(std::vector<std::string> seedData);
    long long findLowestLocatrionOfRange(long long rangeStart, long long rangeEnd, long long stepSize, std::vector<std::vector<mapRange>> rangeMap);
};


#endif //ADVENT1_DAY5PART2_H
