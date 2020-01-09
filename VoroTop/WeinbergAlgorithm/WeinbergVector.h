//
// Created by atara on 9/19/19.
//

#ifndef VOROTOP_WEINBERGVECTOR_H
#define VOROTOP_WEINBERGVECTOR_H

#include "../Graph/Vertex.h"
#include "../Graph/Graph.h"
#include "WeinbergGraph/WeinbergGraph.h"
#include "CanonicalVector.h"

using namespace std;

template <typename T>
class WeinbergVector {
private:
    WeinbergGraph<T>* graph;
    vector<WeinbergVertex<int>*> vertices;
    vector<WeinbergEdge<int>*> edges;
    CanonicalVector* canonicalVector;
    int i = 0;
    void initialize(WeinbergEdge<int>* edge, int u, int v);
    void reset();
    void getFirstWeinVec();
public:
    WeinbergVector(WeinbergGraph<T>* g);
    WeinbergVector();
    void calculate();
    CanonicalVector* getCanonicalVector();
    ~WeinbergVector();
};


#endif //VOROTOP_WEINBERGVECTOR_H
