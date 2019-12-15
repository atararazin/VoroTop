//
// Created by atara on 12/15/19.
//

#include "OutputFile.h"

/**
 * using the name given as input for the input file, create the output file of the same
 * name, but using .wvector.
 * @param fileName
 */
void OutputFile::createFile(std::string fileName) {
    std::string outFileName = fileName.substr(0, fileName.find("."));
    file.open(outFileName + ".wvector");
}

/**
 * writes the values of the canonical vector into the file.
 * format: each vector gets its own line, starting and ending with "(" and ")".
 * each number is separated by a comma, followed by a space.
 * @param vec
 */
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

