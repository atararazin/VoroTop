//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_FACE_H
#define VOROTOP_FACE_H

#include <vector>
#include <string>
using namespace std;

class Face {
private:

public:
    vector<int> nodes;
    void convertStrToVector(string s);
    void print();
};


#endif //VOROTOP_FACE_H