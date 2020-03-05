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
    void writeTofile(std::string s);
    ~OutputFile();

private:
    std::ofstream file;
};


#endif //VOROTOP_OUTPUTFILE_H
