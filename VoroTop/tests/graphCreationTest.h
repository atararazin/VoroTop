//
// Created by atara on 11/28/19.
//

#ifndef VOROTOP_GRAPHCREATIONTEST_H
#define VOROTOP_GRAPHCREATIONTEST_H


#include "../WeinbergAlgorithm/WeinbergVertex.h"
#include "../WeinbergAlgorithm/WeinbergEdge.h"

class graphCreationTest {
private:
    bool test1();
    bool compareVertices(vector<int> desired, vector<WeinbergVertex*> actual);
    bool compareEdges(vector<std::pair<int,int>> desired, vector<WeinbergEdge*> actual);
    void printResults();

public:
    graphCreationTest();


};


#endif //VOROTOP_GRAPHCREATIONTEST_H
