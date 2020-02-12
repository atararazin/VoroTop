//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGGRAPH_H
#define VOROTOP_WEINBERGGRAPH_H

#include "../../Graph/Graph.h"
#include "WeinbergEdge.h"
#include "WeinbergVertex.h"
template <typename T>

class WeinbergGraph : public Graph<T>{
public:
    WeinbergGraph(string faces);
    vector<WeinbergVertex<T>*> vertices;
    vector<WeinbergEdge<T>*> edges;

    void getFaces(string);
    void getVertices();
    void getEdges();
    void reset();
    ~WeinbergGraph();

private:
    int edgeExists(std::pair<T,T> *searching);
    void addEdge(std::pair<T,T> *e, WeinbergVertex<T>*v);
    pair<Face<T>* ,int> findFirstAppearance(WeinbergVertex<int>* v);
    pair<Face<T>* ,int> findPairOfVerticesInFaces(int *v, int *u);
};


#endif //VOROTOP_WEINBERGGRAPH_H
