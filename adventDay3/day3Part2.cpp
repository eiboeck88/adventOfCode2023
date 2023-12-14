//
// Created by aeiboeck on 13.12.2023.
//

#include "day3Part2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <valarray>
#include <vector>

void day3Part2::dataFeeder() {
    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day3.txt");

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }

    int result = 0;
    std::cout << "length of one line " << lines[0].length() << std::endl;

    result += calculatePartNumbers(lines[0], "", lines[1]);

    //std::cout << result << " result after first\n-------------------------------------------" << std::endl;

    for (int lineIierator = 1; lineIierator < lines.size() - 1; lineIierator++) {
        //std::cout << lines[lineIierator] << std::endl;

        result += calculatePartNumbers(lines[lineIierator], lines[lineIierator - 1], lines[lineIierator + 1]);

        std::cout << lineIierator << " <lineiterator : result> " << result
                  << "\n--------------------------------------------" << std::endl;
    }
    result += calculatePartNumbers(lines[lines.size() - 1], lines[lines.size() - 2], "");
    std::cout << result << " end result" << std::endl;
}


int day3Part2::calculatePartNumbers(std::string data, std::string lineAbove, std::string lineBelow) {
    std::cout << lineAbove << "\n" << data << " <\n" << lineBelow
              << " data in function\n__________________________________________________________" << std::endl;
    int result = 0;
    std::string lines[] = {lineAbove, lineBelow, data};

    for (int dataIterator = 0; dataIterator < data.length(); dataIterator++) {
        std::string tempData;


        if (data.at(dataIterator) == '*') {
            int lineIterationStart = 0;
            int lineIteratrionEnd = 0;
            if (lineAbove.empty()) {
                lineIterationStart = 1;
            }
            if (lineBelow.empty()) {
                lineIteratrionEnd = 1;
            }
            std::string tempData[] = {"", "", "", "","",""};

            int currentLine = 0;
            for (int lineIterator = lineIterationStart;
                 lineIterator < (sizeof(lines) / sizeof(lines[0])) - lineIteratrionEnd; lineIterator++) {
                int tempIterator = dataIterator;
                int tempIncrement = -1;
                bool secondNumber = false;
                while (true) {
                    if (tempIncrement == 1 && tempIterator > dataIterator && !isdigit(lines[lineIterator].at(tempIterator))) {
                        break;
                    }
                    if(tempIterator <= 0){
                        tempIncrement = 1;
                    }
                    if (tempIncrement == -1 && !isdigit(lines[lineIterator].at(tempIterator)) && tempIterator < dataIterator) {
                        tempIncrement = 1;
                    }
                    if (tempIncrement == 1) {
                        if (tempIterator == dataIterator && !tempData[0 + currentLine].empty() && !isdigit(lines[lineIterator].at(tempIterator))) {
                            secondNumber = true;
                        }
                        if (isdigit(lines[lineIterator].at(tempIterator)) && !secondNumber) {
                            tempData[0 + currentLine] += lines[lineIterator].at(tempIterator);
                        }
                        if (isdigit(lines[lineIterator].at(tempIterator)) && secondNumber) {
                            tempData[1 + currentLine] += lines[lineIterator].at(tempIterator);
                        }
                    }
                    tempIterator += tempIncrement;
                    if(tempIterator >= data.length()){
                        break;
                    }
                    //std::cout << tempIterator << " iterator " << lines[lineIterator].at(tempIterator) << " dataIterator " << dataIterator << std::endl;

                }
                currentLine += 2;
            }//bug at iteratrion 18

            int tempResultCount = 0;
            std::vector<int> validTempIndexes;
            for (int resultIterator = 0; resultIterator < sizeof(tempData) / sizeof(tempData[0]); resultIterator++) {
                if (!tempData[resultIterator].empty()) {
                    tempResultCount++;
                    validTempIndexes.push_back(resultIterator);
                }
            }
            if (tempResultCount == 2) {

                int debugInteger = stoi(tempData[validTempIndexes[0]]) * stoi(tempData[validTempIndexes[1]]);
                result += debugInteger;
                std::cout << tempData[0] << " top temp data : " << tempData[1] << std::endl;
                std::cout << tempData[4] << " middle temp data : " << tempData[5] << std::endl;
                std::cout << tempData[2] << " bottom temp data : " << tempData[3] << std::endl;
                std::cout << debugInteger << " temp resutl \n+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

            }else{
                std::cout << "no valid calculatrion " << tempResultCount << std::endl;

            }
            //std::cout << tempResultCount << " result count" << std::endl;
        }
    }
    std::cout << result << " < result of function" << std::endl;
    return result;
}//83863920