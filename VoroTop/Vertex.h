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
    vector<Edge> listOfEdges;
public:
    Vertex(int data);
    void print();
};


#endif //VOROTOP_VERTEX_H
