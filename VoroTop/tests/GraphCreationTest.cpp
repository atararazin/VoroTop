//
// Created by atara on 12/5/19.
//

#ifndef VOROTOP_GRAPHCREATIONTEST_H
#define VOROTOP_GRAPHCREATIONTEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph.h"


using testing::Eq;

namespace {
    class GraphCreationTest : public testing::Test {
    public:

        GraphCreationTest() {
        }
    };
}

TEST_F(GraphCreationTest, check_vertices_67){

    string input = "(1,67,66,56,4) (1,57,33,67) (1,4,59,42,39,57) (2,0,35,32) (2,12,14,18,0) (2,32,10,11,13,9,12) "
                          "(3,25,29,19,24,16) (3,21,9,13,5,25) (3,16,23,20,21) (4,56,43,44,46,58,59) "
                          "(5,13,11,6,39,42,38,62,65,63,8,36) (5,36,37,28,22,29,25) (6,11,10,41,40) (6,40,33,57,39) "
                          "(7,45,43,56,66) (7,34,35,0,18,15,26,27,52,53,47,45) (7,66,67,33,40,41,34) (8,37,36) "
                          "(8,63,60,51,55,52,27,31,28,37) (9,21,20,14,12) (10,32,35,34,41) (14,20,23,15,18) (15,23,16,24,26) "
                          "(17,61,62,38) (17,58,46,50,51,60,64,61) (17,38,42,59,58) (19,29,22,30) (19,30,31,27,26,24) "
                          "(22,28,31,30) (43,45,47,49,44) (44,49,48,50,46) (47,53,54,48,49) (48,54,55,51,50) (52,55,54,53) "
                          "(60,63,65,64) (61,64,65,62)";

    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>(input);

    vector<WeinbergVertex<int>*> expectedVertices;
    for(int i = 0; i < 68; i++){
        expectedVertices.push_back(new WeinbergVertex<int>(i));
    }

    ASSERT_THAT(expectedVertices.size(), graph->vertices.size());

    for(int i = 0; i < expectedVertices.size(); i++){
        EXPECT_EQ(expectedVertices[i]->data, graph->vertices[i]->data) << "vertices at" << i << " are not equal";
    }
    delete graph;
}

TEST_F(GraphCreationTest, check_vertices_41){

    string line = "(1,41,40,32,3,34) (1,11,36,41) (1,34,8,17,7,10,4,35,11) (2,8,34,3,12,16,21) (2,20,17,8) (2,21,30,31,22,20) (3,32,37,18,12) (4,33,35) (4,10,6,27,26,33) (5,25,13,28) (5,23,9,15,38,39,27,6,24,25) (5,28,29,23) (6,10,7,0,19,24) (7,17,20,22,0) (9,18,37,14,15) (9,23,29,16,12,18) (11,35,33,26,39,38,36) (13,25,24,19,31,30) (13,30,21,16,29,28) (14,37,32,40) (14,40,41,36,38,15) (19,0,22,31) (26,27,39)";

    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>(line);

    vector<WeinbergVertex<int>*> expectedVertices;
    for(int i = 0; i < 42; i++){
        expectedVertices.push_back(new WeinbergVertex<int>(i));
    }

    ASSERT_THAT(expectedVertices.size(), graph->vertices.size());

    for(int i = 0; i < expectedVertices.size(); i++){
        EXPECT_EQ(expectedVertices[i]->data, graph->vertices[i]->data) << "vertices at" << i << " are not equal";
    }
    delete graph;
}



#endif