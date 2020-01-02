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
    ofstream* inputFile;
    string lineOnlyXYZ(string line);
    void getXyzCols(string line);
public:
    string max_x;
    string min_x;
    string max_y;
    string min_y;
    string max_z;
    string min_z;
    string runStr;
    string compileStr;
    Input(fstream& originalFile);
    void createInputFile(fstream&);
    void updateInputStr();

};


#endif //VOROTOP_INPUT_H
