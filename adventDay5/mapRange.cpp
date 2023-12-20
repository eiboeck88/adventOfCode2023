//
// Created by aeiboeck on 18.12.2023.
//

#include <iostream>
#include "mapRange.h"

void mapRange::setData(long long rangeStartToSet, long long originalRangeToSet, long long rangeToSet) {
    rangeStart = rangeStartToSet;
    rangeEnd = rangeStartToSet + rangeToSet;
    originalRangeStart = originalRangeToSet;
    originalRangeEnd = originalRangeToSet + rangeToSet;
}

long long mapRange::findnewRangeStart(long long rangeStartToCheck) {
    if(rangeStartToCheck > originalRangeStart){
        return translateData(rangeStartToCheck);
    }
    return rangeStart;
}

long long mapRange::findNewRangeEnd(long long rangeEndToCheck) {
    if(rangeEndToCheck < originalRangeEnd){
        return translateData(rangeEndToCheck);
    }
    return translateData(rangeEnd);
}

long long mapRange::translateData(long long numberToConvert) {
    return rangeStart + (numberToConvert - originalRangeStart);
}

long long mapRange::getRangeEnd() {
    return rangeEnd;
}

long long mapRange::getOriginalRangeEnd() {
    return originalRangeEnd;
}

long long mapRange::getRangeStart() {
    return rangeStart;
}

long long mapRange::getOriginalRangeStart() {
    return originalRangeStart;
}