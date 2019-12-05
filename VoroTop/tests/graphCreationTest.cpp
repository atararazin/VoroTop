//
// Created by atara on 11/28/19.
//

#include "graphCreationTest.h"
#include "../WeinbergAlgorithm/WeinbergGraph.h"
#include "../WeinbergAlgorithm/WeinbergVertex.h"

graphCreationTest::graphCreationTest() {
    printResults();
}

bool graphCreationTest::test1() {
    WeinbergGraph* graph = new WeinbergGraph();
    graph->getFaces("(0,1,2) (2,1,3) (0,2,3)");
    graph->getVertices();
    graph->getEdges();
    vector<int> vertices;
    vertices.push_back(0);
    vertices.push_back(1);
    vertices.push_back(2);
    vertices.push_back(3);
    vector<std::pair<int,int>> edges;
    edges.push_back(std::pair<int,int>(0,1));
    edges.push_back(std::pair<int,int>(1,2));
    edges.push_back(std::pair<int,int>(2,0));
    edges.push_back(std::pair<int,int>(1,3));
    edges.push_back(std::pair<int,int>(3,2));
    edges.push_back(std::pair<int,int>(3,0));

    int res1 = compareVertices(vertices, graph->vertices);
    int res2 = compareEdges(edges, graph->edges);
    delete graph;
    return (res1 && res2);
}

bool graphCreationTest::compareVertices(vector<int> desired, vector<WeinbergVertex *> actual) {
    int i = 0;
    for(WeinbergVertex* v : actual){
        if(v->data != desired[i]){
            return false;
        }
        i++;
    }
    return true;
}

bool graphCreationTest::compareEdges(vector<std::pair<int, int>> desired, vector<WeinbergEdge *> actual) {
    int i = 0;
    for(WeinbergEdge* e : actual){
        if(e->edge != desired[i]){
            return false;
        }
        i++;
    }
    return true;
}

void graphCreationTest::printResults() {
    printf("Printing test results for graph creation test:\n");
    if(!test1()){
        printf("test 1 failed\n");
    }
    else{
        printf("all tests passed\n");
    }
    printf("\n\n");
}
