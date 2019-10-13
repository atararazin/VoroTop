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
    vector<Vertex> nodes;
    vector<Edge> edges;
    vector<Face*> faces;
public:
    void convertFromListFaces(string faces);
    void printFaces();
};


#endif //VOROTOP_GRAPH_H
