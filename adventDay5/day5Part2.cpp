//
// Created by alex on 17.12.23.
//

#include "day5Part2.h"
#include "mapRange.h"

void day5Part2::dataFeeder() {

    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day5.txt");

    std::vector<std::string> originalData;
    std::string currentLine;
    std::vector<long long> seeds;

    while (std::getline(adventData, currentLine)) {
        originalData.push_back(currentLine);
    }

    seeds = extractSeedData(originalData[0]);
    std::vector<long long > endResults;
    originalData.erase(originalData.begin(), originalData.begin() + 1);
    std::vector<std::vector<mapRange>> rangeMaps = convertSeedDataIntoRanges(originalData);

    std::freopen("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\adventDay5\\log.txt", "w", stdout);

//    for(int seedIterator = 0; seedIterator < seeds.size(); seedIterator += 2){
//        std::cout << seeds[seedIterator] << " seed " << seeds[seedIterator + 1] << " seed range" << std::endl;
//        endResults.push_back(findLowestLocatrionOfRange(seeds[seedIterator], seeds[seedIterator + 1], 1000, rangeMaps));
//    }
    long long lowestLocNumber = 999999999999999999;

    endResults.push_back(findLowestLocatrionOfRange(seeds[12], seeds[12 + 1], 1000, rangeMaps));
    int tester = 0;
    for(long long test : endResults){
        if(test < lowestLocNumber){
            lowestLocNumber = test;
        }
        std::cout << test << " endResults " << tester<< std::endl;
        tester++;
    }
    std::cout << lowestLocNumber << " real end result " << std::endl;



}


std::vector<long long> day5Part2::extractSeedData(std::string rawSeedData) {
    std::istringstream dataStream(rawSeedData);
    std::vector<long long> seedData;

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
            seedData.push_back(stoll(temp));
        }

    } while (dataStream);

    return seedData;
}

std::vector<std::vector<mapRange>> day5Part2::convertSeedDataIntoRanges(std::vector<std::string> seedData) {
    std::vector<mapRange> rangesCollection;
    std::vector<std::vector<mapRange>> someThing;
    for (int seedDataIterator = 0; seedDataIterator < seedData.size(); seedDataIterator++) {
        mapRange tempMapRanges;
        std::vector<long long> tempSeedRange;

        if (seedData[seedDataIterator].empty()) {
            continue;
        }

        if(!isdigit(seedData[seedDataIterator].at(0))){
            if(!rangesCollection.empty()){
                someThing.push_back(rangesCollection);
                rangesCollection.erase(rangesCollection.begin(), rangesCollection.end());
            }
        }

        tempSeedRange = extractSeedData(seedData[seedDataIterator]);
        if(!tempSeedRange.empty()){
            tempMapRanges.setData(tempSeedRange[0], tempSeedRange[1], tempSeedRange[2]);
            rangesCollection.push_back(tempMapRanges);
        }
        if(seedDataIterator == seedData.size() - 1){
            someThing.push_back(rangesCollection);
            rangesCollection.erase(rangesCollection.begin(), rangesCollection.end());
        }
    }

    return someThing;
}


long long day5Part2::findLowestLocatrionOfRange(long long rangeStart, long long rangeEnd, long long stepSize, std::vector<std::vector<mapRange>> rangeMap) {
//    std::cout << rangeStart << " < range start : range end > " << rangeStart + rangeEnd << " " <<  stepSize << " < step size : range map size > " << rangeMap.size() << std::endl;

    bool firstIteration = true;
    long long lowestLocationNumber = 999999999999999999;
    long long lastIteration = rangeStart;

    for(long long rangeIterator = rangeStart; rangeIterator <= rangeStart + rangeEnd; rangeIterator += stepSize){
        long long numberToCheck = rangeIterator;
//        std::cout << numberToCheck << " start " << std::endl;
        for(int mapIterator = 0; mapIterator < rangeMap.size(); mapIterator++){
            for(int mapRangeIterator = 0; mapRangeIterator < rangeMap[mapIterator].size(); mapRangeIterator++){

                if(numberToCheck >= rangeMap[mapIterator][mapRangeIterator].getOriginalRangeStart() && numberToCheck <= rangeMap[mapIterator][mapRangeIterator].getOriginalRangeEnd()){
                    numberToCheck = rangeMap[mapIterator][mapRangeIterator].translateData(numberToCheck);
//                    std::cout << numberToCheck << " result\n++++++++++++++++++++++++++++++++++++++++++++++++++++++ " << std::endl;
                    break;
                }
            }
        }
        std::cout << numberToCheck << " < result : last iteration > " << lastIteration << std::endl;
        if(lastIteration + stepSize != numberToCheck && stepSize != 1 && !firstIteration){
            firstIteration = false;
            std::cout << " -------------------------------------------------\nrecursion \n--------------------------------------------------------------" << std::endl;
            lastIteration = findLowestLocatrionOfRange(lastIteration, stepSize, 1, rangeMap);
            if(lastIteration < lowestLocationNumber){
                std::cout << "narrwedScope result = " << lastIteration << std::endl;
                lowestLocationNumber = lastIteration;
            }
        }

        if(lowestLocationNumber > numberToCheck){
            lowestLocationNumber = numberToCheck;
//            std::cout << numberToCheck << " lowest location number" << std::endl;
        }

//        std::cout << lastIteration + stepSize << " < last iteratrion : now iteration > " << numberToCheck << std::endl;
        lastIteration = numberToCheck;
        if(firstIteration){
            firstIteration = false;
        }
//        std::cout << "lowest locattion Number = " << lowestLocationNumber << std::endl;
        if(rangeIterator > (rangeStart + rangeEnd) - stepSize){
//            std::cout << "step decreased " << rangeIterator << " range iterator " << rangeStart + rangeEnd << " range end " << stepSize << std::endl;
            stepSize = 1;
        }
    }

    return lowestLocationNumber;
}
