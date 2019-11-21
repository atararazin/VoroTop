//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "Graph/Vertex.h"
#include "Graph/Graph.h"
#include "WeinbergGraph.h"

using namespace std;

class WeinbergVector {
private:
    vector<int> weinbergCode;
    int getVCode(int node);
    int i = 0;
    WeinbergGraph* graph;
    void reset();
public:
    WeinbergVector(WeinbergGraph* g);
    void calculate();
    void recursiveCal(WeinbergVertex* node, WeinbergEdge* branch);

};


#endif //VOROTOP_WEINBERGVECTOR_H
