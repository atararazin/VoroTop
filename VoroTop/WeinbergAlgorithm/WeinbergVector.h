//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "../Graph/Vertex.h"
#include "../Graph/Graph.h"
#include "WeinbergGraph.h"

using namespace std;

class WeinbergVector {
private:
    vector<int> canonicalVector;
    int i = 0;
    WeinbergGraph* graph;
    vector<WeinbergVertex<int>*> vertices;
    vector<WeinbergEdge<int>*> edges;
    void initialize(WeinbergEdge<int>* edge, int u, int v);
    void reset();
    enum Direction {Right, Left};
    Direction direction;
    void updateDirection(Direction d);
    WeinbergEdge<int>* right(WeinbergEdge<int>*,WeinbergVertex<int>*);
    WeinbergEdge<int>* left(WeinbergEdge<int>*,WeinbergVertex<int>*);
    WeinbergEdge<int>* getNeighbor(WeinbergEdge<int>*,WeinbergVertex<int>*);
    string compareToCode(int i);
    void getFirstWeinVec();
public:
    WeinbergVector(WeinbergGraph* g);
    void calculate();
    void recursiveCal(WeinbergVertex<int>* node, WeinbergEdge<int>* branch);
    vector<int> getVector();
};


#endif //VOROTOP_WEINBERGVECTOR_H
