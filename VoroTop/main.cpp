#include <iostream>
#include <fstream>
#include <vector>
#include "Voro++/VoronoiCell.h"
#include "Graph/FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
#include "OutputFile.h"

using namespace std;

//#include<gtest/gtest.h>
//#include<gmock/gmock.h>
#include <chrono>

/*
int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    testing::GTEST_FLAG(filter) = "TimeTest*";
    return RUN_ALL_TESTS();
}*/


using namespace std::chrono;

/*
int main(int argc, char *argv[]) {
    auto start = high_resolution_clock::now();
    fstream file;
    string inputFileName = argv[1];
    file.open(inputFileName);
    fstream& fref = file;

    Input* input = new Input(fref);
    input->max_x = argv[2];
    input->min_x = argv[3];
    input->max_y = argv[4];
    input->min_y = argv[5];
    input->max_z = argv[6];
    input->min_z = argv[7];
    file.close();

    OutputFile* outputFile = new OutputFile();
    outputFile->createFile(inputFileName);

    VoronoiCell* voronoiCell = new VoronoiCell();
    voronoiCell->calcVorCell(input);
    FacesToGraph<int>* graphConverter = new FacesToGraph<int>();
    graphConverter->openOutputFile("inputForVoro++.txt.vol");
    vector<WeinbergGraph<int>*> allGraphs = graphConverter->createGraph();
    for(WeinbergGraph<int>* graph : allGraphs){
        WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
        wvector->calculate();
        outputFile->writeToFile(wvector->getCanonicalVector()->getVector());
        delete(wvector);
    }

    delete(outputFile);
    delete(input);
    delete(voronoiCell);
    delete(graphConverter);

    //for calculating time - delete after
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}*/



int main(int argc, char *argv[]) {
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