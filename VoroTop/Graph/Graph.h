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

template<typename T>
class Graph {
protected:
    virtual void getFaces(string faces) = 0;
    virtual void getVertices() = 0;
    virtual void getEdges() = 0;
    void create(string faces);

public:
    vector<Face<T>*> faces;
};


#endif //VOROTOP_GRAPH_H
