//
// Created by aeiboeck on 12.12.2023.
//

#include "day1Part2.h"
#include "day1.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>

int day1Part2::sumAllStrings() {

    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\test2.txt");
    int dataIndex = 0;

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }

    int result = 0;
    for (std::string line: lines) {
        int numberFromFunction = decipherText(line);
        result += numberFromFunction;
    }

    return result;
}

int day1Part2::decipherText(std::string text) {
    //text = convertStringToInt(text);
    const int digitCount = 2;
    std::string number = "";
    std::vector<std::string> testFinders = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
                                            "nine"};
    std::cout << text << std::endl;

    for (int digitPlacesIterator = 0; digitPlacesIterator < digitCount; digitPlacesIterator++) {
        std::string tempString = "";
        bool wasfound = false;
        for (char someChar: text) {
            tempString += someChar;
            if (isdigit(someChar)) {
                number += someChar;
                break;
            } else {
                for (int someIterator = 0; someIterator < testFinders.size(); someIterator++) {
                    if (tempString.find(testFinders[someIterator]) != std::string::npos) {
                        //std::cout << foundIndex << std::endl;
                        number += std::to_string(someIterator);
                        wasfound = true;
                        break;
                    }
                }
            }
            if (wasfound) {
                break;
            }
        }
        std::reverse(text.begin(), text.end());
        for (int someReverse = 0; someReverse < testFinders.size(); someReverse++) {
            std::reverse(testFinders[someReverse].begin(), testFinders[someReverse].end());
        }
    }

    std::cout << number << std::endl;
    return stoi(number);
}
