//
// Created by atara on 9/16/19.
//

#include "Input.h"

Input::Input(fstream& originalFile){
    this->createInputFile(originalFile);
    //this->updateInputStr();
}

void Input::createInputFile(fstream& originalFile) {
    ofstream file;
    file.open("inputForVoro++.txt");

    string line;
    getline(originalFile, line);
    this->getXyzCols(line);

    try{
        while (getline(originalFile, line)) {
            file << lineOnlyXYZ(line) << endl;
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
    ss << "./voro++ -c %t"<< " " << this->max_x << " " << this->min_x << " " << this->max_y << " " <<
       this->min_y << " " << this->max_z << " " << this->min_z << " " << "inputForVoro++.txt";
    std::string s = ss.str();
    cout << s << "------string now " << endl;
    this->inputStr = s;
}