//
// Created by atara on 11/17/19.
//

#ifndef VOROTOP_WEINBERGGRAPH_H
#define VOROTOP_WEINBERGGRAPH_H

#include "Graph/Graph.h"

class WeinbergGraph : public Graph{
    void getFaces(string);
    void getVertices();
    void getEdges();

    /*for printing only*/
    void printE();
    void printFaces();
    void printV();
    void printG();

};


#endif //VOROTOP_WEINBERGGRAPH_H
