//
// Created by aeiboeck on 12.12.2023.
//

#include "day2.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

void day2::possibleGame() {
    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day2test.txt");
    int dataIndex = 0;

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }
    int possibleGames = 0;
    for(std::string line : lines){
        int gameNumber;
        int foundTokenIndex = line.find(':');
        int foundToke2Index = line.find('e');

        gameNumber = stoi(line.substr(foundToke2Index + 1,foundTokenIndex));
        line.erase(0,foundTokenIndex + 1);

        std::cout << "\n" << gameNumber << " <gameNumber : possibleGames> " << possibleGames << std::endl;

        if(findColorCount(line)){
            possibleGames += gameNumber;
        }
    }

    std::cout << possibleGames << " result"<< std::endl;
}

int day2::findColorCount(const std::string& gameData) {

    std::istringstream testStream(gameData);
    std::cout << gameData << " gamedata" << std::endl;
    std::vector<std::string> colors = {"red", "green", "blue"};
    std::vector<int> colorCount = {12,13,14};
    std::vector<int> minColor = {0,0,0};
    //testStream.seekg();

    do {
        std::string subString;
        int subInt;
        testStream >> subInt;
        testStream >> subString;
        //std::cout << "ianputdata : " << subString << " " << subInt << std::endl;
        for(int someIterator = 0; someIterator < colors.size(); someIterator++){
            if(subString.contains(colors[someIterator]) && subInt > colorCount[someIterator]){
                return false;
            }
        }

    } while (testStream);

    return true;
}
