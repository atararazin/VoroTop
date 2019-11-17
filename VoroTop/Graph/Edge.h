//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_EDGE_H
#define VOROTOP_EDGE_H


#include <ostream>

class Edge {
public:
    std::pair<int,int> edge;
    Edge(std::pair<int,int> e);
    std::pair<int,int> getEdge();
    std::pair<int,int> getOppEdge();
    void updateStatus();
    bool operator==(const Edge& other);
    void print();


};


#endif //VOROTOP_EDGE_H
