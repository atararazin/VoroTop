//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "Vertex.h"
using namespace std;

class WeinbergVector {
private:
    vector<int> weinbergCode;
public:
    void calculate(Graph graph);
    void recursiveCal(Vertex node, Edge branch, Edge original);

};


#endif //VOROTOP_WEINBERGVECTOR_H
