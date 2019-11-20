//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGEDGE_H
#define VOROTOP_WEINBERGEDGE_H


#include "Graph/Edge.h"

class WeinbergEdge : public Edge{
public:
    std::pair<int,int> edge;
    WeinbergEdge(std::pair<int,int> edge);
    enum Status{NOTVISITED, NEW, OLD};
    int getStatus();
    void updateStatus();
private:
    Status status = NOTVISITED;
};


#endif //VOROTOP_WEINBERGEDGE_H
