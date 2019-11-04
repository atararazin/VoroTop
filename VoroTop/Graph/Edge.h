//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_EDGE_H
#define VOROTOP_EDGE_H


#include <ostream>

class Edge {
public:
    enum Status{NOTVISITED, NEW, OLD};
    Edge(std::pair<int,int >);
    std::pair<int,int> getEdge();
    void updateStatus();
    int getStatus();
    void print();
private:
    std::pair<int,int> edge;
    Status status = NOTVISITED;


};


#endif //VOROTOP_EDGE_H
