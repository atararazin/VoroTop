//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_FACE_H
#define VOROTOP_FACE_H

#include <vector>
#include <string>
using namespace std;
template <typename T>
class Face {
private:

public:
    vector<T> nodes;
    void convertStrToVector(string s);
};


#endif //VOROTOP_FACE_H
