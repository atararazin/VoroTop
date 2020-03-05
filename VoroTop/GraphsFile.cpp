//
// Created by atara on 2/17/20.
//

#include <iostream>
#include "GraphsFile.h"
/***
 * class of the file that's the output from voro++
 */

/***
 * constructor. opens the file.
 * @param filePath
 * @return
 */
GraphsFile::GraphsFile(string filePath) {
    try{
        file.open(filePath);
    }
    catch(char* excp){
        cout << "Caught " << excp << "trying to open voro++ output file" << endl;
        exit(-1);
    }
    string line;
    while(getline(file, line)){
        size++;
    }
    file.clear();
    file.seekg(0);
}

int GraphsFile::getSize() {
    return size;
}

/**
 * reads one line aka one graph from the voro++ output file.
 * @return the line
 */
std::string GraphsFile::readOneLine() {
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

GraphsFile::~GraphsFile() {
    file.close();
}