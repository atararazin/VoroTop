//
// Created by atara on 12/15/19.
//

#ifndef VOROTOP_OUTPUTFILE_H
#define VOROTOP_OUTPUTFILE_H
#include <iostream>
#include <fstream>
#include <vector>


class OutputFile {
public:
    void createFile(std::string);
    void writeToFile(std::vector<int>*, int);
    void closeFile();
    std::ofstream* getFile();
    ~OutputFile();

private:
    std::ofstream file;
};


#endif //VOROTOP_OUTPUTFILE_H
