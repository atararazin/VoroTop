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
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)");

    //graph->getFaces("(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)");
    //graph->getVertices();
    //graph->getEdges();

    WeinbergVertex<int>* two = graph->vertices[2];
    EXPECT_EQ((two->getEdges()[0]->forwardEdge()), (std::pair<int,int>(2,9)));
    WeinbergEdge<int >* expected0 = new WeinbergEdge<int >(4,2);
    EXPECT_EQ(expected0->forwardEdge(), two->getRightMostNeighbor(two->getEdges()[0])->forwardEdge());


    WeinbergEdge<int >* expected1 = new WeinbergEdge<int >(6,2);
    EXPECT_EQ(expected1->forwardEdge(), two->getRightMostNeighbor(two->getEdges()[1])->forwardEdge());

    WeinbergEdge<int >* expected2 = new WeinbergEdge<int >(6,2);
    EXPECT_EQ(expected2->forwardEdge(), two->getLeftMostNeighbor(two->getEdges()[0])->forwardEdge());


    delete graph;
    delete expected0;
    delete expected1;
    delete expected2;
}


TEST_F(NeighborsTest, test2){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,3,2,0) (1,5,7,3) (1,0,4,5) (2,6,4,0) (2,3,7,6) (4,6,7,5)");

    EXPECT_EQ((graph->vertices[1]->getEdges()[0]->forwardEdge()),(std::pair<int,int>(1,3)));
    EXPECT_EQ((graph->vertices[1]->getRightMostNeighbor(graph->vertices[1]->getEdges()[0])->forwardEdge()),(std::pair<int,int>(0,1)));
    EXPECT_EQ((graph->vertices[1]->getRightMostNeighbor(graph->vertices[1]->getEdges()[1])->forwardEdge()),(std::pair<int,int>(5,1)));

    EXPECT_EQ((graph->vertices[1]->getLeftMostNeighbor(graph->vertices[1]->getEdges()[0])->forwardEdge()),(std::pair<int,int>(5,1)));
    EXPECT_EQ((graph->vertices[1]->getLeftMostNeighbor(graph->vertices[1]->getEdges()[1])->forwardEdge()),(std::pair<int,int>(1,3)));
    delete graph;
}

TEST_F(NeighborsTest, test3_triangle){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(0,1,2) (2,1,0)");

    EXPECT_EQ((graph->vertices[1]->getEdges()[0]->forwardEdge()),(std::pair<int,int>(1,2)));
    EXPECT_EQ((graph->vertices[1]->getRightMostNeighbor(graph->vertices[1]->getEdges()[0])->forwardEdge()),(std::pair<int,int>(0,1)));
    EXPECT_EQ((graph->vertices[1]->getLeftMostNeighbor(graph->vertices[1]->getEdges()[0])->forwardEdge()),(std::pair<int,int>(0,1)));

    delete graph;
}

#endif