//
// Created by aeiboeck on 12.12.2023.
//

#include "day1.h"
#include <iostream>
#include <fstream>
#include <vector>

int day1::sumAllStrings() {

    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\dataDay1.txt");

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData,currentLine)){
        lines.push_back(currentLine);
    }

    int result = 0;
    for(std::string line : lines){
        int numberFromFunction = stoi(decipherText(line));
        result += numberFromFunction;
    }

    return result;
}

std::string day1::decipherText(std::string text) {
    const int digitCount = 2;
    std::string number = "";

    for(int digitPlacesIterator = 0; digitPlacesIterator < digitCount; digitPlacesIterator++){
        if(number.length() == 0){
            for(int stringIterator = 0; stringIterator <= text.length(); stringIterator++){
                if(isdigit(text.at(stringIterator))){
                    number += text.at(stringIterator);
                    break;
                }
            }
        } else{
            for(int stringIterator = text.length() -1; stringIterator >= 0; stringIterator--){
                if(isdigit(text.at(stringIterator))){
                    number += text.at(stringIterator);
                    break;
                }
            }
        }
    }
    return number;
}