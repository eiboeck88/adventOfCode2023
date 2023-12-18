//
// Created by alex on 17.12.23.
//

#include "day5.h"

void day5::dataFeeder() {

    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day5.txt");

    //std::vector<long long> seedData = {104847962, 3583832, 1212568077, 114894281, 3890048781, 333451605, 1520059863, 217361990, 310308287, 12785610, 3492562455, 292968049, 1901414562, 516150861, 2474299950, 152867148, 3394639029, 59690410, 862612782, 176128197};
    std::vector<long long> seedData;
    std::string currentLine;
    std::getline(adventData, currentLine);
    if (currentLine.contains("seeds:")) {
        seedData = extractSeedData(currentLine);
    }

    std::vector<std::vector<long long>> seedMapData;
    while (std::getline(adventData, currentLine)) {
        if (currentLine.empty()) {
            continue;
        }
        if (!isdigit(currentLine.at(0))) {
            if (!seedMapData.empty()) {
                seedData = calculateSeedMap(seedMapData, seedData);
            }
//            for (long long test: seedData) {
//                std::cout << test << " seedData" << std::endl;
//            }
            std::cout << "\n-----------------------------------------------------\n" << std::endl;
//            std::cout << currentLine << std::endl;

            seedMapData.erase(seedMapData.begin(), seedMapData.end());
            continue;
        }
        seedMapData.push_back(extractSeedData(currentLine));
    }
    seedData = calculateSeedMap(seedMapData, seedData);
    for (long long test: seedData) {
        std::cout << test << std::endl;
    }
    std::cout << findSmallestLocation(seedData) << " lowest location number" << std::endl;


}

long long day5::findSmallestLocation(std::vector<long long> seedData) {
    long long smallestLocation = seedData[0];
    for(long long seed : seedData){
        if(seed < smallestLocation){
            smallestLocation = seed;
        }
    }
    return smallestLocation;
}

std::vector<long long> day5::extractSeedData(std::string rawSeedData) {
    std::istringstream dataStream(rawSeedData);
    std::vector<long long> seedData;
    std::cout << rawSeedData << " raw seed data" << std::endl;
    do {
        std::string temp;
        dataStream >> temp;
        std::cout << temp << " temp in extract" << std::endl;
        if (!temp.empty() && !isdigit(temp.at(0))) {
            continue;
        }
        if (!temp.empty() && isdigit(temp.at(0))) {
            seedData.push_back(stoll(temp));
        }
    } while (dataStream);
    return seedData;
}

std::vector<long long> day5::calculateSeedMap(std::vector<std::vector<long long>> seedMapRange, std::vector<long long> seedData) {
    std::vector<long long> finnishedSeedData;

//    for(std::vector<long long> test : seedMapRange){
//        for(long long yay : test){
//            std::cout << yay << " ";
//        }
//        std::cout << "\n--------------------------------" << std::endl;
//    }

    for(long long seedIterator = 0; seedIterator < seedData.size(); seedIterator++){
        for(long long seedMapIterator = 0; seedMapIterator < seedMapRange.size(); seedMapIterator++){
            if(seedData[seedIterator] >= seedMapRange[seedMapIterator][1] && seedData[seedIterator] <= seedMapRange[seedMapIterator][1] + seedMapRange[seedMapIterator][2]){
//                std::cout << seedData[seedIterator] << " before " << std::endl;
                seedData[seedIterator] = seedMapRange[seedMapIterator][0] + (seedData[seedIterator] - seedMapRange[seedMapIterator][1]);
//                std::cout << seedData[seedIterator] << " after \n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
                break;
            }
        }
    }
    return seedData;
}