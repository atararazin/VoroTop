//
// Created by atara on 9/16/19.
//

#include "Input.h"

Input::Input(fstream& originalFile){
    this->initializeMinMaxVars(originalFile);
    this->createInputFile(originalFile);
    this->inputStr;
}

void Input::createInputFile(fstream& originalFile) {
    fstream file;
    file.open("inputForVoro++.txt");

    string line;
    int lineNum = 1;
    while (lineNum!= 10 && getline(originalFile, line)) {
        lineNum++;
    }

    try{
        while (getline(originalFile, line)) {
            istringstream iss(line);
            file << lineWithoutType(line) << endl;
        }
    }
    catch(...){
        cout << "error reading from file" << endl;
        exit(-1);
    }

    file.close();
    this->inputFile = &file;
}

void Input::getXyzCols(string line) {

}

string Input::lineWithoutType(string line) {
    istringstream iss(line);
    string s;
    string ret;
    int i = 0;
    while ( getline( iss, s, ' ' ) ) {
        if(i != 1){
            ret += s.c_str();
            ret += " ";
        }
        i++;
    }
    return ret;
}

void Input::initializeMinMaxVars(fstream &originalFile) {
    int lineNum = 1;
    string line;
    while (lineNum != 6 && getline(originalFile, line)) {
        lineNum++;
    }

    string num[2];
    getline(originalFile, line);
    this->splitNums(line, num);
    this->max_x = num[0];
    this->min_x = num[1];

    getline(originalFile, line);
    this->splitNums(line, num);
    this->max_y = num[0];
    this->min_y = num[1];

    getline(originalFile, line);
    this->splitNums(line, num);
    this->max_z = num[0];
    this->min_z = num[1];
}


void Input::splitNums(string line, string nums[2]) {
    string s;
    istringstream iss(line);
    getline( iss, s, ' ' );
    nums[0] = s.c_str();
    getline( iss, s, ' ' );
    nums[1] = s.c_str();
}

void Input::updateInputStr() {
    std::stringstream ss;
    ss << "./voro++ -c %t" << this->max_x << " " << this->min_x << " " << this->max_y << " " <<
       this->min_y << " " << this->max_z << " " << this->min_z << " " << "inputForVoro++.txt";
    std::string s = ss.str();
    cout << s << "------string now " << endl;
    this->inputStr = s;
}