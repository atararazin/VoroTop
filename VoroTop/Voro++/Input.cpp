//
// Created by atara on 9/16/19.
//

#include "Input.h"

Input::Input(std::string originalFile){
    this->createInputFile(originalFile);
    this->updateInputStr();
}

void Input::createInputFile(std::string OFName) {
    ofstream file;
    file.open("./voro++-0.4.6/src/inputVoro++");
    originalFile.open(OFName);
    string line;


    do{
        getline(originalFile, line);
    }while(line.find("ITEM: BOX BOUNDS") != 0);


    getline(originalFile, line);
    while(line.find("ITEM: ATOMS") != 0){
        minMaxXYZStr += line;
        minMaxXYZStr += " ";
        getline(originalFile,line);
    }

    this->getXyzCols(line);
    while (getline(originalFile, line)) {
        file << lineOnlyXYZ(line) << endl;
    }
    file.close();
}

void Input::getXyzCols(string line) {
    istringstream iss(line);
    string s;
    int i = 0;
    while ( getline( iss, s, ' ' ) ) {
        if(s == "x"){
            this->xyzCols[0] = i-2;
        }
        if(s == "y"){
            this->xyzCols[1] = i-2;
        }
        if(s == "z"){
            this->xyzCols[2] = i-2;
        }
        i++;
    }
}

string Input::lineOnlyXYZ(string line) {
    istringstream iss(line);
    string s;
    string ret;
    int x = this->xyzCols[0];
    int y = this->xyzCols[1];
    int z = this->xyzCols[2];

    int i = 0;
    while ( getline( iss, s, ' ' ) ) {
        if(i == x or i == y or i == z){
            ret += s.c_str();
            ret += " ";
        }
        i++;
    }
    return ret;
}


void Input::updateInputStr() {
    std::stringstream ss;
    ss << "./voro++ -p -c %t"<< " " << minMaxXYZStr << "inputVoro++";
    std::string s = ss.str();
    this->inputString = s;
}

std::string Input::getInputString() {
    return inputString;
}