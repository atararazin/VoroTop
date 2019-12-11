//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_EDGE_H
#define VOROTOP_EDGE_H


#include <ostream>
template <typename T>

class Edge {
public:
    Edge(std::pair<T,T> e);
    Edge(T u,T v);
    std::pair<T,T> forwardEdge();
    std::pair<T,T> backwardEdge();
    bool operator== (Edge const &obj);

protected:
    T u;
    T v;
    std::pair<T,T> forward;
    std::pair<T,T> backwards;
};


#endif //VOROTOP_EDGE_H
