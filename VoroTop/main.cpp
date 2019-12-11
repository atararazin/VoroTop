#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "VoronoiCell.h"
#include "FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
using namespace std;

#include<gtest/gtest.h>
#include<gmock/gmock.h>


int main(int argc, char*argv[]){
    testing::InitGoogleTest(&argc, argv);
    //testing::GTEST_FLAG(filter) = "VerticesCreationTest*";
    return RUN_ALL_TESTS();
}



/*
int main(int argc, char *argv[]) {
    fstream file;
    file.open(argv[1]);
    fstream& fref = file;

    Input* input = new Input(fref);
    input->max_x = argv[2];
    input->min_x = argv[3];
    input->max_y = argv[4];
    input->min_y = argv[5];
    input->max_z = argv[6];
    input->min_z = argv[7];
    file.close();

    VoronoiCell* voronoiCell = new VoronoiCell();
    voronoiCell->calcVorCell(input);
    FacesToGraph* graphConverter = new FacesToGraph();
    graphConverter->openOutputFile();
    vector<WeinbergGraph*> allGraphs = graphConverter->createGraph();
    for(WeinbergGraph* graph : allGraphs){
        WeinbergVector* wvector = new WeinbergVector(graph);
        wvector->calculate();
        delete(wvector);
    }

    delete(input);
    delete(voronoiCell);
    delete(graphConverter);
}*/