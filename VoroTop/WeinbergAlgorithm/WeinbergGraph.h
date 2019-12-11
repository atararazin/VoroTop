//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGGRAPH_H
#define VOROTOP_WEINBERGGRAPH_H

#include "../Graph/Graph.h"
#include "WeinbergEdge.h"
#include "WeinbergVertex.h"

class WeinbergGraph : public Graph{
public:
    vector<WeinbergVertex<int>*> vertices;
    vector<WeinbergEdge<int>*> edges;

    void getFaces(string);
    void getVertices();
    void getEdges();
    ~WeinbergGraph();

private:
    int edgeExists(std::pair<int,int> searching);
    void addEdge(std::pair<int,int> e, WeinbergVertex<int>*v);
    pair<Face* ,int> findFirstAppearance(int v);
    int* findFirstAppearance2(int v);
    pair<Face* ,int> findPairOfVerticesInFaces(int v, int u);


};


#endif //VOROTOP_WEINBERGGRAPH_H
