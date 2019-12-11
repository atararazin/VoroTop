//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_VERTEX_H
#define VOROTOP_VERTEX_H

#include <vector>
#include "Edge.h"

using namespace std;
template <typename T>

class Vertex {
    protected:
        vector<Edge<T>*> listOfEdges;
    public:
        T data;
        Vertex(T const& data) : data(data) {}
        //vector<Edge*> getEdges();
        //void addEdge(Edge* e);
        bool operator==(const Vertex& other);
        bool operator()(const Vertex& obj) const;
    };




#endif //VOROTOP_VERTEX_H
