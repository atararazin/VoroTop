//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGGRAPH_H
#define VOROTOP_WEINBERGGRAPH_H

#include "../Graph/Graph.h"
#include "WeinbergEdge.h"
#include "WeinbergVertex.h"
template <typename T>

class WeinbergGraph : public Graph{
public:
    vector<WeinbergVertex<T>*> vertices;
    vector<WeinbergEdge<T>*> edges;

    void getFaces(string);
    void getVertices();
    void getEdges();
    ~WeinbergGraph();

private:
    int edgeExists(std::pair<T,T> searching);
    void addEdge(std::pair<T,T> e, WeinbergVertex<T>*v);
    pair<Face* ,int> findFirstAppearance(WeinbergVertex<int>* v);
    int* findFirstAppearance2(int v);
    pair<Face* ,int> findPairOfVerticesInFaces(int v, int u);


};


#endif //VOROTOP_WEINBERGGRAPH_H
