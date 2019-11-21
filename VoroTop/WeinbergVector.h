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
    int i = 0;
    WeinbergGraph* graph;
    vector<WeinbergVertex*> vertices;
    vector<WeinbergEdge*> edges;
    void initialize(WeinbergEdge* edge, int u, int v);
    void reset();
public:
    WeinbergVector(WeinbergGraph* g);
    void calculate();
    void recursiveCal(WeinbergVertex* node, WeinbergEdge* branch);

};


#endif //VOROTOP_WEINBERGVECTOR_H
