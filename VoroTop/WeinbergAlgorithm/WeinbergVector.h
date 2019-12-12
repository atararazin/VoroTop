//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "../Graph/Vertex.h"
#include "../Graph/Graph.h"
#include "WeinbergGraph.h"
#include "CanonicalVector.h"
#include "Direction.h"

using namespace std;

template <typename T>
class WeinbergVector {
private:
    CanonicalVector* canonicalVector;
    Direction* direction;
    int i = 0;
    bool first = true;
    WeinbergGraph<T>* graph;
    vector<WeinbergVertex<int>*> vertices;
    vector<WeinbergEdge<int>*> edges;
    void initialize(WeinbergEdge<int>* edge, int u, int v);
    void reset();
    WeinbergEdge<int>* getNeighbor(WeinbergEdge<int>*,WeinbergVertex<int>*);
    void getFirstWeinVec();
public:
    WeinbergVector(WeinbergGraph<T>* g);
    void calculate();
    void recursiveCal(WeinbergVertex<int>* node, WeinbergEdge<int>* branch);
    CanonicalVector* getVector();
    ~WeinbergVector();
};


#endif //VOROTOP_WEINBERGVECTOR_H
