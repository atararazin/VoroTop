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
    void reset();
public:
    WeinbergVector(WeinbergGraph<T>* g);
    WeinbergVector();
    void calculate();
    vector<int>& getCanonicalVector();
    ~WeinbergVector();
};


#endif //VOROTOP_WEINBERGVECTOR_H
