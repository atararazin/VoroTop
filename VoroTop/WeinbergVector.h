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
    vector<int> canonicalVector;
    int i = 0;
    WeinbergGraph* graph;
    vector<WeinbergVertex*> vertices;
    vector<WeinbergEdge*> edges;
    void initialize(WeinbergEdge* edge, int u, int v);
    void reset();
    //WeinbergEdge* (*WeinbergVector::dir)(WeinbergEdge*, WeinbergVertex*);
    enum Direction {Right, Left};
    Direction direction;
    void updateDirection(Direction d);
    WeinbergEdge* right(WeinbergEdge*,WeinbergVertex*);
    WeinbergEdge* left(WeinbergEdge*,WeinbergVertex*);
    WeinbergEdge* getNeighbor(WeinbergEdge*,WeinbergVertex*);
    int compareToCode(int i);
public:
    WeinbergVector(WeinbergGraph* g);
    void calculate();
    void recursiveCal(WeinbergVertex* node, WeinbergEdge* branch);
};


#endif //VOROTOP_WEINBERGVECTOR_H
