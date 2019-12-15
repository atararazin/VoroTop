//
// Created by atara on 12/15/19.
//

#ifndef VOROTOP_WEINBERGVECTORMETHODSTEST_H
#define VOROTOP_WEINBERGVECTORMETHODSTEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"
#include "../WeinbergAlgorithm/WeinbergVector.h"


using testing::Eq;

namespace {
    class WeinbergVectorMethods : public testing::Test {
    public:

        WeinbergVectorMethods() {
        }
    };
}

TEST_F(WeinbergVectorMethods, check_getFirstWeinVec){

    string line = "(1,67,66,56,4) (1,57,33,67) (1,4,59,42,39,57) (2,0,35,32) (2,12,14,18,0) (2,32,10,11,13,9,12) "
                          "(3,25,29,19,24,16) (3,21,9,13,5,25) (3,16,23,20,21) (4,56,43,44,46,58,59) "
                          "(5,13,11,6,39,42,38,62,65,63,8,36) (5,36,37,28,22,29,25) (6,11,10,41,40) (6,40,33,57,39) "
                          "(7,45,43,56,66) (7,34,35,0,18,15,26,27,52,53,47,45) (7,66,67,33,40,41,34) (8,37,36) "
                          "(8,63,60,51,55,52,27,31,28,37) (9,21,20,14,12) (10,32,35,34,41) (14,20,23,15,18) (15,23,16,24,26) "
                          "(17,61,62,38) (17,58,46,50,51,60,64,61) (17,38,42,59,58) (19,29,22,30) (19,30,31,27,26,24) "
                          "(22,28,31,30) (43,45,47,49,44) (44,49,48,50,46) (47,53,54,48,49) (48,54,55,51,50) (52,55,54,53) "
                          "(60,63,65,64) (61,64,65,62)";
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>(line);

    WeinbergVector<int>* vec = new WeinbergVector<int>(graph);
    delete graph;
    delete vec;

}

#endif
