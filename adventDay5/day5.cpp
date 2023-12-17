//
// Created by alex on 17.12.23.
//

#include "day5.h"

void day5::day5Run() {

    std::ifstream adventData("/home/alex/CLionProjects/advent/recurces/day5test.txt");

    std::vector <std::string> lines;
    std::string currentLine;

    while (std::getline(adventData, currentLine)) {
        lines.push_back(currentLine);
    }
    std::vector<int> seedData;

    seedData = findSeedData(lines[0]);


    lines.erase(lines.begin());
    lines.erase(lines.begin());

    for(int testIterator = 0; testIterator < 5; testIterator++){
//        for(std::string nope : lines){
//            std::cout << nope << std::endl;
//        }

        seedData = mapSeed(seedData, lines);
        std::cout << std::endl;
    }

    //    while (!lines.empty()){
//
//    }

    for(int lkj : seedData){
        std::cout << lkj << " seeds after" << std::endl;
    }


}

std::vector<int> day5::findSeedData(std::string data) {
    std::vector<int> seedData;
    std::istringstream dataStream(data);

    do {
        std::string temp;
        dataStream >> temp;
        if (!temp.empty() && isdigit(temp.at(0))) {
            seedData.push_back(stoi(temp));
        }

    } while (dataStream);

    return seedData;
}

void day5::eraseLines(int currentLine, std::vector <std::string> &data) {
    data.erase(data.begin());
}

std::vector<int> day5::mapSeed(std::vector<int> seedData, std::vector <std::string> &data) {
    std::vector<int> finnishedSeed;

    if(!isdigit(data[0].at(0))){
        eraseLines(0,data);
    }

    for (int test = 0; test < data.size(); test++) {
        std::vector<int> curentRange;
        bool isOver = false;
        std::cout << " current line " << data[test] << std::endl;

        if(data[test].empty()){
            break;
        }
        std::istringstream dataStream(data[test]);


        do {
            std::string temp;
            dataStream >> temp;
            std::cout << temp << " temp"<< std::endl;

            if(!temp.empty() && !isdigit(temp.at(0))){
                isOver = true;
                break;
            }

            if (!temp.empty()){
                if(isdigit(temp.at(0))){
                    curentRange.push_back(stoi(temp));
                }
            }
        } while (dataStream);

        if (isOver) {
            break;
        }

        //eraseLines(test, data);
//        for(int ranges : curentRange){
//            std::cout << ranges << " ";
//        }

        for(int hoit = 0; hoit < seedData.size(); hoit++){

            if(seedData[hoit] > curentRange[1] && seedData[hoit] < curentRange[1] + curentRange[2]){
                finnishedSeed.push_back(curentRange[0] + (seedData[hoit] - curentRange[1]));
                seedData.erase(seedData.begin() + hoit);
            }
        }
    }

    if(!seedData.empty()){
        for(int remainingSeeds : seedData){
            finnishedSeed.push_back(remainingSeeds);
        }
    }
    return finnishedSeed;
}

