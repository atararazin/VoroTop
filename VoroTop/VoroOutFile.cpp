//
// Created by atara on 2/17/20.
//

#include <iostream>
#include "VoroOutFile.h"
/***
 * voro++'s output file.
 */

VoroOutFile::VoroOutFile(string filePath) {
    try{
        file.open(filePath);
    }
    catch(char* excp){
        cout << "Caught " << excp << "trying to open voro++ output file" << endl;
        exit(-1);
    }

    countLines();

}

/**
 * counts the number of lines in the file.
 */
void VoroOutFile::countLines() {
    string line;
    while(getline(file, line)){
        size++;
    }
    file.clear();
    file.seekg(0);
}

int VoroOutFile::getSize() {
    return size;
}

/**
 * reads one line aka one graph from the voro++ output file.
 * @return the line
 */
std::string VoroOutFile::readOneLine() {
    string line;
    try{
        getline(file, line);
        return line;
    }
    catch(char* excp){
        cout << "Caught " << excp << "while trying to read from voro++ output file" << endl;
        exit(-1);
    }

}

VoroOutFile::~VoroOutFile() {
    file.close();
}