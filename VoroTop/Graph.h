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
    vector<Vertex*> nodes;
    vector<Edge*> edges;
    vector<Face*> faces;
    template<typename T>
    vector<T> removeDups(vector<T> v, typename vector<T>::iterator ip);
    void removeDupsEdges(vector<Edge*>);
    void addEdgesToVertices(vector<Edge>);

public:
    void getFaces(string faces);
    void printFaces();
    void getVertices(string faces);
    void printV();
    void getEdges();
    void printE();
};


#endif //VOROTOP_GRAPH_H
