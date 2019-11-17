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
    virtual void getFaces(string faces) = 0;
    virtual void getVertices() = 0;
    virtual void getEdges() = 0;
    void assignEdgesToVertices();


public:
    vector<Vertex*> vertices;
    vector<Edge*> edges;
    vector<Face*> faces;
    void create(string faces);
    ~Graph();
};


#endif //VOROTOP_GRAPH_H
