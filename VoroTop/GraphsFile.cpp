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
        cout << "Caught " << excp << endl;
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