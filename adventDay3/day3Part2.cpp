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

        std::cout << lineIierator << " <lineiterator : result> " << result << "\n--------------------------------------------" << std::endl;
    }
    result += calculatePartNumbers(lines[lines.size() - 1], lines[lines.size() - 2], "");
    std::cout << result << std::endl;
}


int day3Part2::calculatePartNumbers(std::string data, std::string lineAbove, std::string lineBelow) {
    std::cout << lineAbove << "\n" << data << " <\n" << lineBelow << " data in function\n__________________________________________________________" << std::endl;
    int result = 0;
    for (int dataIterator = 0; dataIterator < data.length(); dataIterator++) {
        std::string tempData;


        if (data.at(dataIterator) == '*') {
            int tempindex = dataIterator;

            int topIncrement = -1;

            int topIterator = tempindex + topIncrement;

            std::string topTemp;

            bool wasBackTop = false;

            while (true) {
                if (topIncrement == 1 && !isdigit(lineAbove.at(topIterator))) {
                    break;
                }
                if (topIncrement == -1 && !isdigit(lineAbove.at(topIterator))) {
                    topIncrement = 1;
                    topIterator++;
                }
                if(topIterator == 0){
                    topIncrement = 1;
                }
                if (topIncrement == 1 && isdigit(lineAbove.at(topIterator))) {
                    topTemp += lineAbove.at(topIterator);
                }

                topIterator += topIncrement;
                std::cout << topIterator << " top iterator"<< tempindex << std::endl;
            }
            std::cout << topTemp << " top temp" << std::endl;

            int bottomIncrement = -1;
            int bottomIterator = tempindex + bottomIncrement;
            std::string bottomTemp;
            while (true) {
                //std::cout << bottomIterator << " bottom iterator " << tempindex << std::endl;
                if (bottomIncrement == 1 && !isdigit(lineBelow.at(bottomIterator))) {
                    break;
                }
                if (bottomIncrement == -1 && !isdigit(lineBelow.at(bottomIterator))) {
                    bottomIncrement = 1;
                    bottomIterator++;
                }
                if(bottomIterator == 0){
                    bottomIncrement = 1;
                }
                if (bottomIncrement == 1) {
                    bottomTemp += lineBelow.at(bottomIterator);
                }
                bottomIterator += bottomIncrement;
            }
            std::cout << bottomTemp << " bot temp" << std::endl;
            if(!topTemp.empty() && !bottomTemp.empty()){
                result = stoi(topTemp) * stoi(bottomTemp);
            }

        }
    }
    std::cout << result << " < result of function" << std::endl;
    return result;
}