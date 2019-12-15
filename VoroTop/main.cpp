#include <iostream>
#include <fstream>
#include <vector>
#include "VoronoiCell.h"
#include "FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
#include "OutputFile.h"

using namespace std;

#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include <chrono>


int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    //testing::GTEST_FLAG(filter) = "VerticesCreationTest*";
    return RUN_ALL_TESTS();
}
 /*
using namespace std::chrono;


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
    graphConverter->openOutputFile();
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
}
*/