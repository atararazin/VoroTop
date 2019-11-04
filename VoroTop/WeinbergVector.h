//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "Graph/Vertex.h"
#include "Graph/Graph.h"

using namespace std;

class WeinbergVector {
private:
    vector<int> weinbergCode;
    int getVCode(int node);
    int i = 0;
    Graph* graph;
public:
    WeinbergVector(Graph* g);
    void calculate();
    void recursiveCal(Vertex* node, Edge* branch, Edge* original);

};


#endif //VOROTOP_WEINBERGVECTOR_H
