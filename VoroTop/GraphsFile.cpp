//
// Created by atara on 2/17/20.
//

#include <iostream>
#include "GraphsFile.h"

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
        cout << "Caught " << excp << endl;
    }
}

pair<string, int> GraphsFile::readOneLine() {
    string line;
    if(getline(file, line)){
        upto++;
        return pair<string, int>(line, upto);
    }
    else{
        return pair<string, int>("",-1);
    }
}

GraphsFile::~GraphsFile() {
    file.close();
}