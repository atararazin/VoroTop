//
// Created by atara on 10/13/19.
//

#ifndef VOROTOP_GRAPHSCONTAINER_H
#define VOROTOP_GRAPHSCONTAINER_H

#include <vector>
#include "Graph.h"


class GraphsContainer {
public:
    vector<Graph> graphs;
    void addGraph(Graph);
};


#endif //VOROTOP_GRAPHSCONTAINER_H
