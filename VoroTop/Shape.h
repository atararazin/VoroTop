//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_SHAPE_H
#define VOROTOP_SHAPE_H

#include "Face.h"
using namespace std;



class Shape {
private:
    vector<Face> vectorOfFaces;
public:
    void addFace(Face);

};


#endif //VOROTOP_SHAPE_H
