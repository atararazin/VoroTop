//
// Created by atara on 12/9/19.
//


#ifndef VOROTOP_WEINBERGALGORITHMTEST_H
#define VOROTOP_WEINBERGALGORITHMTEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph.h"
#include "../WeinbergAlgorithm/WeinbergVector.h"


using testing::Eq;

namespace {
    class WeinbergAlgorithmTest : public testing::Test {
    public:

        WeinbergAlgorithmTest() {
        }
    };
}


TEST_F(WeinbergAlgorithmTest, test_){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>();

    graph->getFaces("(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)");
    graph->getVertices();
    graph->getEdges();

    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected = {1,2,3,1,3,4,5,6,1,6,7,8,2,8,9,4,9,10,5,10,7,10,9,8,7,6,5,4,3,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]);
    }
    delete(weinbergVector);
    delete graph;
}


TEST_F(WeinbergAlgorithmTest, test_triange){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>();

    graph->getFaces("(0,1,2) (2,1,0)");
    graph->getVertices();
    graph->getEdges();

    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected(7);
    expected = {1,2,3,1,3,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]);
    }

    delete(weinbergVector);
    delete graph;
}


TEST_F(WeinbergAlgorithmTest, test3){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>();

    graph->getFaces("(0,1,2) (0,2,3) (0,3,2,1)");
    graph->getVertices();
    graph->getEdges();

    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected(11);
    expected = {1,2,3,1,3,2,4,1,4,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]) << "iteration:" << i;
    }

    delete(weinbergVector);
    delete graph;
}

#endif //VOROTOP_WEINBERGALGORITHMTEST_H