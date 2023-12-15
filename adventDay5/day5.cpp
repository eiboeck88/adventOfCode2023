//
// Created by aeiboeck on 15.12.2023.
//

#include "day5.h"

void day5::dataFeeder() {
    std::ifstream adventData("C:\\Users\\aeiboeck\\CLionProjects\\advent1\\recurces\\day5test.txt");

    std::vector<std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }

    std::vector<std::vector<int >> seperatedData = seperateData(lines);
    //getCorrosPonding(51,seperatedData);

}

std::vector<std::vector<int>> day5::seperateData(std::vector<std::string> data) {
    std::vector<std::vector<int>> fillTemp;
    std::vector<int> fillFillTemp;
    std::regex dataRegex("\\d+|^\\w+");
    auto endRegex = std::sregex_iterator();

    int index = 0;
    for(int dataIterator = 0; dataIterator < data.size(); dataIterator++){

        std::regex_iterator someRegex = std::sregex_iterator  (data[dataIterator].begin(), data[dataIterator].end(), dataRegex);
        for(std::sregex_iterator something = someRegex; something != endRegex; ++something){
            std::smatch myMatch = *something;
            std::string tempString = myMatch.str();
            if(!isdigit(tempString.at(0))){
                continue;
            }
            if(isdigit(tempString.at(0))){
                std::cout << tempString << std::endl;
            }
        }

        if(data[dataIterator].empty()){
            std::cout << " empty " << std::endl;
            index = dataIterator;
            break;
        }
        index++;
    }



    for(int yay = 0; yay < index; yay++){
        data.erase(data.begin());
    }

    for(std::string lol : data){
        std::cout << lol << std::endl;
    }

    return fillTemp;
}

int day5::getCorrosPonding(int seed, std::vector<std::vector<int>> data) {

    for(int dataIterator = 0; dataIterator < data.size(); dataIterator++){
        for(int rangeIterator = 0; rangeIterator < data[dataIterator][2]; rangeIterator++){

            if(seed == data[dataIterator][1] + rangeIterator){
                std::cout << data[dataIterator][1] << " raw data " << data[dataIterator][1] + rangeIterator << " foud seed" << std::endl;
            }
        }
    }

    return 0;
}

//std::vector<std::vector<int>> day5::calculateRanges(std::vector<std::vector<int>> data) {
//}

