//
// Created by atara on 9/16/19.
//

#ifndef VOROTOP_INPUT_H
#define VOROTOP_INPUT_H

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;


class Input {
public:
    Input(std::string);
    void createInputFile(std::string);
    void updateInputStr();
    std::string getInputString();
private:
    int xyzCols[3];
    ofstream* inputFile;
    fstream originalFile;
    string lineOnlyXYZ(string line);
    void getXyzCols(string line);
    string minMaxXYZStr = "";
    string inputString;

};


#endif //VOROTOP_INPUT_H
