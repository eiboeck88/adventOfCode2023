//
// Created by aeiboeck on 18.12.2023.
//

#ifndef ADVENT1_MAPRANGE_H
#define ADVENT1_MAPRANGE_H

#include <vector>

class mapRange {
private:
    long long range;
    long long rangeStart;
    long long rangeEnd;
    long long originalRangeStart;
    long long originalRangeEnd;
    long long newRangeStart;
    long long newRangeEnd;
public:
    long long translateData(long long numberToConvert);
    void setData(long long rangeStart, long long originalRange , long long range);
    long long getRangeStart();
    long long getRangeEnd();
    long long getOriginalRangeStart();
    long long getOriginalRangeEnd();
    long long findnewRangeStart(long long rangeStart);
    long long findNewRangeEnd(long long rangeEnd);
};


#endif //ADVENT1_MAPRANGE_H
