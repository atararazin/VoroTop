//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_GRAPH_H
#define VOROTOP_GRAPH_H


class Graph {
private:
    vector<Node> nodes;
    vector<Edge> edges;
public:
    void convertFromListFaces(string faces);
};


#endif //VOROTOP_GRAPH_H
