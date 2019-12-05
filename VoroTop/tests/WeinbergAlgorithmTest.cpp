//
// Created by atara on 11/28/19.
//

#include "WeinbergAlgorithmTest.h"

WeinbergAlgorithmTest::WeinbergAlgorithmTest() {
    printResults();
}


void WeinbergAlgorithmTest::printResults() {
    printf("Printing test results for weinberg algorithms test:\n");
    if(!test1()){
        printf("test 1 failed\n");
    }
    else{
        printf("all tests passed\n");
    }
    printf("\n\n");

}

bool WeinbergAlgorithmTest::test1() {

}