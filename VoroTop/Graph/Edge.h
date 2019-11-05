//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_EDGE_H
#define VOROTOP_EDGE_H


#include <ostream>

class Edge {
public:
    enum Status{NOTVISITED, NEW, OLD};
    std::pair<int,int> edge;
    Edge(std::pair<int,int >);
    std::pair<int,int> getEdge();
    std::pair<int,int> getOppEdge();
    void updateStatus();
    int getStatus();
    bool operator==(const Edge& other);
    void print();
private:
    Status status = NOTVISITED;


};


#endif //VOROTOP_EDGE_H
