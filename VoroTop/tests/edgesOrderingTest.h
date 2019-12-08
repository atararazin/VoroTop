//
// Created by atara on 12/5/19.
//

#ifndef VOROTOP_EDGESORDERINGTEST_H
#define VOROTOP_EDGESORDERINGTEST_H

//
// Created by atara on 12/5/19.
//

include "edgesOrderingTest.h"
include<gtest/gtest.h>
include<gmock/gmock.h>
include <gmock/gmock-matchers.h>
include "../WeinbergAlgorithm/WeinbergGraph.h"


using testing::Eq;

namespace {
    class edgesOrderingTest : public testing::Test {
    public:
        WeinbergGraph graph;

        edgesOrderingTest() {
            graph;//could put here a method
        }
    };
}

TEST_F(edgesOrderingTest, test1){
    graph.getEdges();
    std::string s = "22";
    ASSERT_THAT(s, graph.toStringEdges());
}





#endif //VOROTOP_EDGESORDERINGTEST_H
