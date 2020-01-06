//
// Created by atara on 12/9/19.
//


#ifndef VOROTOP_WEINBERGALGORITHMTEST_H
#define VOROTOP_WEINBERGALGORITHMTEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"
#include "../WeinbergAlgorithm/WeinbergVector.h"
#include "../OutputFile.h"
#include "../Graph/FacesToGraph.h"
#include <fstream>


using testing::Eq;

namespace {
    class WeinbergAlgorithmTest : public testing::Test {
    public:

        WeinbergAlgorithmTest() {
        }
        bool filesEqual(string s1,string s2);

    };
}
/*

TEST_F(WeinbergAlgorithmTest, test_){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,4,2,9) (1,0,8,4) (1,9,5,3,0) (2,6,7,5,9) (2,4,8,6) (3,7,6,8,0) (3,5,7)");

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
    graph = new WeinbergGraph<int>("(0,1,2) (2,1,0)");

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
    graph = new WeinbergGraph<int>("(0,1,2) (0,2,3) (0,3,2,1)");

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


TEST_F(WeinbergAlgorithmTest, test4){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,19,16,18,12) (1,6,30,4,19) (1,12,32,33,28,27,6) (2,3,5,25,13,21,17) (2,0,16,19,4,14,3) (2,17,10,9,32,12,18,0) (3,14,31,7,5) (4,30,31,14) (5,7,26,29,23,8,15,25) (6,27,26,7,31,30) (8,24,20,21,13,15) (8,23,11,35,22,24) (9,34,35,11,33,32) (9,10,20,24,22,34) (10,17,21,20) (11,23,29,28,33) (13,25,15) (16,0,18) (22,35,34) (26,27,28,29)");

    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected(11);
    expected = {1,2,3,1,3,4,5,6,1,6,7,8,9,10,2,10,11,12,13,14,4,14,15,16,17,18,5,18,19,7,19,20,8,20,21,22,9,22,23,24,25,11,25,26,12,26,27,28,29,13,29,30,31,15,31,32,33,16,33,34,17,34,21,34,33,32,35,36,23,36,24,36,35,27,35,32,31,30,28,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]) << "iteration:" << i;
    }

    delete(weinbergVector);
    delete graph;
}



TEST_F(WeinbergAlgorithmTest, test5){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,23,25,22,21) (1,16,10,11,23) (1,21,20,16) (2,0,19,18) (2,13,4,9,8,0) (2,18,14,28,29,6,13) (3,17,27,26,5) (3,12,17) (3,5,20,21,22,24,7,28,14,15,12) (4,13,6,11,10) (4,10,16,20,5,26,9) (6,29,7,24,25,23,11) (7,29,28) (8,9,26,27) (8,27,17,12,15,19,0) (14,18,19,15) (22,25,24)");
    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected(11);
    expected = {1,2,3,1,3,4,5,6,1,6,7,8,9,10,2,10,11,12,13,14,15,16,17,4,17,18,5,18,19,7,19,20,21,8,21,22,23,12,23,24,13,24,25,26,27,28,14,28,15,28,27,29,16,29,30,20,30,26,30,29,27,26,25,22,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,9,11,10,9,8,7,6,5,4,3,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]) << "iteration:" << i;
    }

    delete(weinbergVector);
    delete graph;
}

TEST_F(WeinbergAlgorithmTest, test6){
    WeinbergGraph<int>* graph;
    graph = new WeinbergGraph<int>("(1,11,13,6,28,29,18) (1,25,23,21,30,31,11) (1,18,22,25) (2,14,6,13,0,5,8,7) (2,17,10,16,19,22,18,29,24,14) (2,7,9,27,17) (3,15,12,26) (3,9,7,8,20,30,21,15) (3,26,27,9) (4,10,17,27,26,12) (4,16,10) (4,12,15,21,23,19,16) (5,0,31,30,20) (5,20,8) (6,14,24,28) (11,31,0,13) (19,23,25,22) (24,29,28)");
    WeinbergVector<int>* weinbergVector = new WeinbergVector<int>(graph);
    weinbergVector->calculate();
    vector<int> expected(11);
    expected ={1,2,3,1,3,4,5,1,5,6,7,8,9,2,9,10,11,12,13,14,15,4,15,16,17,18,19,6,19,20,7,20,21,22,23,24,8,24,10,24,23,11,23,22,25,26,27,12,27,13,27,26,28,29,14,29,30,16,30,31,25,31,28,31,30,29,28,26,25,22,21,32,17,32,18,32,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    ASSERT_THAT(expected.size(), weinbergVector->getCanonicalVector()->getVector().size());
    for(int i =0; i<expected.size(); i++){
        EXPECT_EQ(expected[i], weinbergVector->getCanonicalVector()->getVector()[i]) << "iteration:" << i;
    }

    delete(weinbergVector);
    delete graph;
}


TEST_F(WeinbergAlgorithmTest, 100_tests){
    OutputFile* outputFile = new OutputFile();
    outputFile->createFile("graphs");
    FacesToGraph<int>* graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("/home/atara/VoroTop/tests/graphs");
    vector<WeinbergGraph<int>*> allGraphs = graphConverter->createGraph();
    for(WeinbergGraph<int>* graph : allGraphs){
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(wvector);
    }

    outputFile->closeFile();
    bool ans = filesEqual("/home/atara/VoroTop/tests/weinberg_vectors","graphs.wvector");
    EXPECT_EQ(ans, true);
    delete(outputFile);
    delete(graphConverter);

}

bool WeinbergAlgorithmTest::filesEqual(string s1,string s2){
    fstream file1,file2;
    file1.open(s1);
    file2.open(s2);
    string line;
    char string1[1000], string2[1000];
    int j;
    j = 0;
    bool equal = true;

    while(!file1.eof())
    {
        file1.getline(string1,1000);
        file2.getline(string2,1000);
        j++;
        if(strcmp(string1,string2) != 0)
        {
            equal = false;
            cout << j << "-th strings are not equal" << "\n";
            cout << "String 1:" << string1 << "\n";
            cout << "String 2:" << string2 << "\n";
        }
    }
    file1.close();
    file2.close();

    if(equal == true ){
        printf("THE FILES ARE EQUAL!\n");
        return true;
    }
    return false;

}*/

/*
TEST_F(WeinbergAlgorithmTest, createFileForComp){
    OutputFile* outputFile = new OutputFile();
    outputFile->createFile("graphs1");
    FacesToGraph<int>* graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("/home/atara/VoroTop/tests/graphs1");
    vector<WeinbergGraph<int>*> allGraphs = graphConverter->createGraph();
    for(WeinbergGraph<int>* graph : allGraphs){
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(wvector);
    }

    outputFile->closeFile();
    delete(outputFile);
    delete(graphConverter);

}*/

#endif //VOROTOP_WEINBERGALGORITHMTEST_H