//
// Created by atara on 12/9/19.
//


#ifndef VOROTOP_EDGESORDERINGTEST_H
#define VOROTOP_EDGESORDERINGTEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph.h"


using testing::Eq;

namespace {
    class NeighborsTest : public testing::Test {
    public:

        NeighborsTest() {
        }
    };
}

TEST_F(NeighborsTest, test_2s_right_neighbors){
    WeinbergGraph* graph;
    graph = new WeinbergGraph();

    graph->getFaces("(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)");
    graph->getVertices();
    graph->getEdges();

    WeinbergVertex* two = graph->vertices[2];
    WeinbergEdge* expected0 = new WeinbergEdge(4,2);
    EXPECT_EQ(expected0->forwardEdge(), two->getRightMostNeighbor(two->getEdges()[0])->forwardEdge());


    WeinbergEdge* expected1 = new WeinbergEdge(6,2);
    EXPECT_EQ(expected1->forwardEdge(), two->getRightMostNeighbor(two->getEdges()[1])->forwardEdge());

    delete graph;
}

#endif //VOROTOP_EDGESORDERINGTEST_H