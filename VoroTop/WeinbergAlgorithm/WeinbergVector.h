//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "../Graph/Vertex.h"
#include "../Graph/Graph.h"
#include "WeinbergGraph/WeinbergGraph.h"
#include "CanonicalVector.h"
#include "Direction.h"

using namespace std;

template <typename T>
class WeinbergVector {
private:
    WeinbergGraph<T>* graph;
    vector<WeinbergVertex<int>*> vertices;
    vector<WeinbergEdge<int>*> edges;
    CanonicalVector* canonicalVector;
    Direction* direction;
    int i = 0;
    //int index = 0;
    bool foundSmaller = false;
    bool first = true;
    void initialize(WeinbergEdge<int>* edge, int u, int v);
    void reset();
    WeinbergEdge<int>* getNeighbor(WeinbergEdge<int>*,WeinbergVertex<int>*);
    void getFirstWeinVec();
    void checkBiggerOrSmaller(int code);
public:
    //WeinbergVector(WeinbergGraph<T>* g);
    WeinbergVector();
    void setGraph(WeinbergGraph<T>* graph);
    void calculate();
    void recursiveCal(WeinbergVertex<int>* node, WeinbergEdge<int>* branch);
    CanonicalVector* getCanonicalVector();
    ~WeinbergVector();
};


#endif //VOROTOP_WEINBERGVECTOR_H
