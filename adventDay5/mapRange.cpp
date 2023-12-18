//
// Created by aeiboeck on 18.12.2023.
//

#include <iostream>
#include "mapRange.h"

void mapRange::setData(long long rangeStart, long long possibleRange, long long range){
    std::vector<long long> temp = {rangeStart, rangeStart + range, possibleRange};
    internalData.push_back(temp);
}

long long mapRange::translateData(long long numberToConvert, int index) {
    std::cout << internalData[index][0] << " " << numberToConvert << " " << internalData[index][0] << std::endl;
    return internalData[index][0] + (numberToConvert - internalData[index][2]);
}

long long mapRange::getRangeStart(int index) {
    return internalData[index][0];
}

long long mapRange::getRangeEnd(int index) {
    return internalData[index][1];
}