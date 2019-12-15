//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGEDGE_H
#define VOROTOP_WEINBERGEDGE_H


#include "../../Graph/Edge.h"

template <typename T>

class WeinbergEdge : public Edge<T>{
public:
    WeinbergEdge(T u, T v) : Edge<T>(u, v){};
    enum Status{NOTVISITED, NEW, OLD};
    int getStatus();
    void updateStatus();
    std::pair<T,T> getDirectedEdge(int node);
    void reset();

private:
    Status status = NOTVISITED;
};


#endif //VOROTOP_WEINBERGEDGE_H
