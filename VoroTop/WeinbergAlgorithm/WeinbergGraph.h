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
    vector<WeinbergVertex*> vertices;
    vector<WeinbergEdge*> edges;

    void getFaces(string);
    void getVertices();
    void getEdges();
    ~WeinbergGraph();

    /*for printing only*/
    void printE();
    void printFaces();
    void printV();
    void printG();
    std::string toStringEdges();
private:
    int edgeExists(pair<int,int> searching);
    void addEdge(pair<int,int> e, WeinbergVertex*v);
    pair<Face* ,int> findFirstAppearance(int v);
    pair<Face* ,int> findPairOfVerticesInFaces(int v, int u);


};


#endif //VOROTOP_WEINBERGGRAPH_H
