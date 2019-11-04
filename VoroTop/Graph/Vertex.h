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
        vector<Edge*> listOfEdges;
        int weinNum = -1;
    public:
        int data;
        bool old = false;
        //Vertex(int data);
        Vertex(const int& data) : data(data) {}
        int getData() const;
        vector<Edge*> getEdges();
        void addEdge(Edge* e);
        Edge* getRightMostNeighbor();
        int getWeinNum(int* i);
        bool operator==(const Vertex& other) const;
        bool operator()(const Vertex& obj) const;
        void print();
    };




#endif //VOROTOP_VERTEX_H
