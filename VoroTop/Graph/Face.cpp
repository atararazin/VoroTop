//
// Created by atara on 9/19/19.
//

#include <sstream>
#include <iostream>
#include "Face.h"
/**
 * coverts the line (a string) into a vector of Ts.
 * goes over the string and gets each substring (each number) using "," as its delimiter.
 * @param s
 */
template <typename T>
void Face<T>::convertStrToVector(string s) {
    string str = s.substr(1, s.size()-2);
    istringstream iss(str);
    string num;
    while (getline(iss, num, ',')) {
        this->nodes.push_back(stoi(num));
    }
}

template class Face<int>;
