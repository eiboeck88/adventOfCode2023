//
// Created by alex on 17.12.23.
//

#include "day5Part2.h"
#include "mapRange.h"

void day5Part2::dataFeeder() {

    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day5test.txt");

    std::vector<std::string> originalData;
    std::string currentLine;
    std::vector<long long> seeds;

    while (std::getline(adventData, currentLine)) {
        originalData.push_back(currentLine);
    }

    seeds = extractSeedData(originalData[0]);


    mapRange testRange;
    testRange.setData(52, 50, 48);
    for (int yay = 0; yay < seeds.size(); yay ++) {
        if (seeds[yay] > testRange.getRangeStart(0) && seeds[yay] < testRange.getRangeEnd(0)){
            seeds[yay] = testRange.translateData(seeds[yay], 0);
        }
    }

    for(long long yes : seeds){
        std::cout << yes << " its me yay" << std::endl;
    }
}

std::vector<long long> day5Part2::extractSeedData(std::string rawSeedData) {
    std::istringstream dataStream(rawSeedData);
    std::vector<long long> seeds;

    do {
        std::string temp;
        dataStream >> temp;
        if (temp.empty()) {
            continue;
        }
        if (!isdigit(temp.at(0))) {
            continue;
        }
        if (isdigit(temp.at(0))) {
            seeds.push_back(stoll(temp));
        }

    } while (dataStream);

    return seeds;
}
