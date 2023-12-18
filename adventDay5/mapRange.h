//
// Created by aeiboeck on 18.12.2023.
//

#ifndef ADVENT1_MAPRANGE_H
#define ADVENT1_MAPRANGE_H

#include <vector>

class mapRange {
private:
    std::vector<std::vector<long long >> internalData;
public:
    long long translateData(long long numberToConvert, int index);
    void setData(long long rangeStart,long long possibleRange , long long range);
    long long getRangeStart(int index);
    long long getRangeEnd(int index);

};


#endif //ADVENT1_MAPRANGE_H
