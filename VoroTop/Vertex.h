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
};


#endif //VOROTOP_VERTEX_H
