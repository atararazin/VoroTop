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
    public:
        int data;
        Vertex(const int& data) : data(data) {}
        vector<Edge*> getEdges();
        void addEdge(Edge* e);
        bool operator==(const Vertex& other);
        bool operator()(const Vertex& obj) const;
        void print();
        void printEdges(vector<Edge*>);
    };




#endif //VOROTOP_VERTEX_H
