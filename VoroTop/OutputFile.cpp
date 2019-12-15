//
// Created by atara on 12/15/19.
//

#include "OutputFile.h"

void OutputFile::createFile(std::string fileName) {
    std::string outFileName = fileName.substr(0, fileName.find("."));
    file.open(outFileName + ".wvector");
}

void OutputFile::writeToFile(std::vector<int> vec) {
    file << "(";
    long n = vec.size();
    for(int i  = 0; i < n - 1; i++){
        file << vec[i] << ", ";
    }
    file << vec[n - 1] << ")" << std::endl;
}

OutputFile::~OutputFile(){
    file.close();
}

