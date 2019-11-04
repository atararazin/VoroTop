//
// Created by atara on 9/19/19.
//

#include <sstream>
#include <iostream>
#include "Face.h"

void Face::convertStrToVector(string s) {
    string str = s.substr(1, s.size()-2);
    istringstream iss(str);
    string num;
    while (getline(iss, num, ',')) {
        this->nodes.push_back(stoi(num));
    }
}


void Face::print() {
    for(int i=0; i<this->nodes.size(); ++i)
        std::cout << nodes[i] << ' ';
    std::cout << "" <<std::endl;
}