//
// Created by atara on 12/8/19.
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
        WeinbergGraph graph;

        GraphCreationTest() {
            graph;
        }
    };
}

TEST_F(GraphCreationTest, test1){
    graph.getEdges();
    std::string s = "22";

    EXPECT_EQ(s, graph.toStringEdges());
}





#endif //VOROTOP_GRAPHCREATIONTEST_H
