//
// Created by aeiboeck on 13.12.2023.
//

#include "day3.h"
#include <iostream>
#include <fstream>
#include <valarray>

void day3::dataFeeder() {
    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day3.txt");

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }
    int result = 0;
    std::cout << "length of one line " << lines[0].length() << std::endl;

    result += calculatePartNumbers(lines[0], "", lines[1]);

    std::cout << result << " result after first\n-------------------------------------------" << std::endl;

    for(int lineIierator = 1; lineIierator < lines.size() - 1; lineIierator++){
        //std::cout << lines[lineIierator] << std::endl;

        result += calculatePartNumbers(lines[lineIierator], lines[lineIierator -1], lines[lineIierator + 1]);

        std::cout << lineIierator << " <lineiterator : result> " << result << "\n--------------------------------------------" << std::endl;
    }
    result += calculatePartNumbers(lines[lines.size() - 1], lines[lines.size() -2],"");
    std::cout << result << std::endl;
}



int day3::calculatePartNumbers(std::string data, std::string lineAbove, std::string lineBelow) {
    std::cout << lineAbove << "\n" << data << " <\n" <<lineBelow << " data in function\n__________________________________________________________" << std::endl;
    int result = 0;
    for (int dataIterator = 0; dataIterator < data.length(); dataIterator++) {
        std::string tempData;

        int tempindex = dataIterator;
        if(tempindex != 0){
            tempindex--;
        }

        while (isdigit(data.at(dataIterator))) {
            tempData += data.at(dataIterator);
            if(dataIterator == data.length() - 1){
                break;
            }
            dataIterator++;
            //std::cout << dataIterator << " " << tempindex << " " << tempData << std::endl;
        }


        if(!tempData.empty()){
            for(int mehIterator = tempindex; mehIterator <= dataIterator; mehIterator++){
                if(!lineAbove.empty() && lineAbove.at(mehIterator) != '.' && !isdigit(lineAbove.at(mehIterator))){
                    std::cout << tempData << " tempdata" << std::endl;
                    result += stoi(tempData);
                    break;
                }else if(!lineBelow.empty() && lineBelow.at(mehIterator) != '.' && !isdigit(lineBelow.at(mehIterator))){
                    std::cout << tempData << " tempdata" << std::endl;
                    result += stoi(tempData);
                    break;
                }else if(tempindex > 0 && data.at(tempindex) != '.'){
                    std::cout << tempData << " tempdata" << std::endl;
                    result += stoi(tempData);
                    break;
                }else if(dataIterator < data.size() -1 && data.at(dataIterator) != '.'){
                    std::cout << tempData << " tempdata" << std::endl;
                    result += stoi(tempData);
                    break;
                }
            }
            tempData = "";
        }
    }
    std::cout << result << " < result of function" <<std::endl;
    return result;
}