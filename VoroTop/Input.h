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
private:
    int xyzCols[3];
    fstream* inputFile;
    string lineWithoutType(string line);
    void splitNums(string line, string nums[2]);
    void getXyzCols(string line);
public:
    string max_x;
    string min_x;
    string max_y;
    string min_y;
    string max_z;
    string min_z;
    Input(fstream& originalFile);
    string inputStr;
    void createInputFile(fstream&);
    void initializeMinMaxVars(fstream &);
    void updateInputStr();

};


#endif //VOROTOP_INPUT_H
