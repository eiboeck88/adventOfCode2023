//
// Created by aeiboeck on 14.12.2023.
//

#include "day4.h"
#include <vector>
#include <fstream>
#include <sstream>

void day4::dataFeeder() {
    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day3.txt");

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }
    calculatePoints(lines[0]);
}

int day4::calculatePoints(std::string data) {

    std::stringstream dataStream(data);

    do{
        dataStream >>
    } while (dataStream);

}