//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_VERTEX_H
#define VOROTOP_VERTEX_H

#include <vector>
#include "Edge.h"
using namespace std;

    class Vertex {
    private:
        int data;
        vector<pair<int,int>> listOfEdges;
    public:
        bool old = false;
        Vertex(int data);
        void addEdge(Edge e);
        Edge getRightMostNeighbor();
        void print();
    };




#endif //VOROTOP_VERTEX_H
