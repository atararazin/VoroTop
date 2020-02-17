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
    void createFile(std::string fileName);
    void writeToFile(std::vector<int>* vec);
    void closeFile();
    std::ofstream* getFile();
    ~OutputFile();

private:
    std::ofstream file;
};


#endif //VOROTOP_OUTPUTFILE_H
