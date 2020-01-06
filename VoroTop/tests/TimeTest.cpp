
#ifndef VOROTOP_TIMETEST_H
#define VOROTOP_TIMETEST_H


#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "../WeinbergAlgorithm/WeinbergGraph/WeinbergGraph.h"
#include "../WeinbergAlgorithm/WeinbergVector.h"
#include "../OutputFile.h"
#include "../Graph/FacesToGraph.h"
#include <fstream>
#include <chrono>


using namespace std::chrono;
using testing::Eq;

namespace {
    class TimeTest : public testing::Test {
    public:

        TimeTest() {
        }

    };
}

/*
TEST_F(TimeTest, 2lines) {
    auto start = high_resolution_clock::now();

    OutputFile *outputFile = new OutputFile();
    outputFile->createFile("graphs");
    FacesToGraph<int> *graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("/home/atara/VoroTop/tests/graphs3");
    int numOfGraphs = graphConverter->getNumOfGraphs();

    for(int i = 0; i < numOfGraphs; i++){
        WeinbergGraph<int> *graph = graphConverter->createSingleGraph();
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(wvector);
        delete(graph);

    }
    outputFile->closeFile();
    delete(outputFile);
    delete(graphConverter);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}*/


TEST_F(TimeTest, 100test) {
    printf("running the test");
    auto start = high_resolution_clock::now();

    OutputFile *outputFile = new OutputFile();
    outputFile->createFile("graphs");
    FacesToGraph<int> *graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("/home/atara/VoroTop/tests/graphs");
    int numOfGraphs = graphConverter->getNumOfGraphs();
    WeinbergVector<int>* wvector = new WeinbergVector<int>();

    for(int i = 0; i < numOfGraphs; i++){
        WeinbergGraph<int> *graph = graphConverter->createSingleGraph();
        wvector->setGraph(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(graph);
    }
    outputFile->closeFile();
    delete(wvector);
    delete(outputFile);
    delete(graphConverter);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}

/*
TEST_F(TimeTest, 1mtest) {
    auto start = high_resolution_clock::now();

    OutputFile *outputFile = new OutputFile();
    outputFile->createFile("graphs");
    FacesToGraph<int> *graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("/home/atara/VoroTop/tests/graphs1");
    int numOfGraphs = graphConverter->getNumOfGraphs();

    for(int i = 0; i < numOfGraphs; i++){
        WeinbergGraph<int> *graph = graphConverter->createSingleGraph();
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(wvector);
        delete(graph);

    }
    outputFile->closeFile();
    delete(outputFile);
    delete(graphConverter);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}*/

#endif