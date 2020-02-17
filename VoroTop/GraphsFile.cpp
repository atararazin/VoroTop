//
// Created by atara on 2/17/20.
//

#include <iostream>
#include "GraphsFile.h"
GraphsFile::GraphsFile(string filePath) {
    try{
        file.open(filePath);
    }
    catch(char* excp){
        cout << "Caught " << excp << endl;
    }
}

string GraphsFile::readOneLine() {
    string line;
    if(getline(file, line)){
        return line;
    }
    else{
        return "";
    }
}

GraphsFile::~GraphsFile() {
    file.close();
}