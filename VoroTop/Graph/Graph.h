//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_GRAPH_H
#define VOROTOP_GRAPH_H

#include <vector>
#include <string>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
using namespace std;


class Graph {
private:
    void getFaces(string faces);
    void getVertices();
    void getEdges();
    void assignEdgesToVertices();

    /*for printing only*/
    void printE();
    void printFaces();
    void printV();

public:
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    vector<Face*> faces;
    void create(string faces);
    ~Graph();
};


#endif //VOROTOP_GRAPH_H
