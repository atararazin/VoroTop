//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGEDGE_H
#define VOROTOP_WEINBERGEDGE_H


#include "../Graph/Edge.h"

template <typename T>

class WeinbergEdge : public Edge<T>{
public:
    //std::pair<int,int> edge;
    WeinbergEdge(std::pair<int,int> edge) : Edge<int>(edge){};
    WeinbergEdge(int u, int v) : Edge<int>(u, v){};
    enum Status{NOTVISITED, NEW, OLD};
    int getStatus();
    void updateStatus();
    //std::pair<int, int> backwardEdge();
    std::pair<int,int> getDirectedEdge(int node);
    void reset();

private:
    Status status = NOTVISITED;
    //int u;
    //int v;
    //std::pair<int,int> u_v;
    //std::pair<int,int> v_u;

};


#endif //VOROTOP_WEINBERGEDGE_H
