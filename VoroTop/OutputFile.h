//
// Created by atara on 12/15/19.
//

#ifndef VOROTOP_OUTPUTFILE_H
#define VOROTOP_OUTPUTFILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <map>


class OutputFile {
public:
    void createFile(std::string);
    void saveData(std::vector<int>&, int);
    void closeFile();
    std::ofstream* getFile();
    ~OutputFile();

private:
    std::ofstream file;
    int index = 0;
    std::map<int, std::vector<int>> waitingQueue;
    void writeToFile(std::vector<int>&);
    void writeWaitingToFile(int curr);
};


#endif //VOROTOP_OUTPUTFILE_H
