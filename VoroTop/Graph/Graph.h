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
    void printFaces();
    void getVertices(string faces);
    void printV();
    void getEdges();
    void printE();
    void assignEdgesToVertices();
public:
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    vector<Face*> faces;
    void create(string faces);
    ~Graph();
};


#endif //VOROTOP_GRAPH_H
