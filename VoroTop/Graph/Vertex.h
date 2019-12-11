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
    public:
        T data;
        Vertex(T const& data) : data(data) {}
        bool operator==(const Vertex& other);
        bool operator()(const Vertex& obj) const;
};




#endif //VOROTOP_VERTEX_H
