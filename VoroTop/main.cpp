#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include "Voro++/VoronoiCell.h"
#include "Graph/FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
#include "OutputFile.h"
#include "GraphsFile.h"
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

void readAndWrite();

OutputFile *outputFile;
GraphsFile *voroOutputFile;
bool stop = false;
std::mutex inFileMutex;
std::mutex outFileMutex;

int main(int argc, char *argv[]) {
    printf("running");
    auto start = high_resolution_clock::now();

    outputFile = new OutputFile();
    outputFile->createFile("graphs");
    voroOutputFile = new GraphsFile("/home/atara/VoroTop/tests/graphs");

    std::thread t1(readAndWrite);
    std::thread t2(readAndWrite);
    std::thread t3(readAndWrite);
    std::thread t4(readAndWrite);
    std::thread t5(readAndWrite);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    //while(!stop){
    //    readAndWrite();
    //}
    outputFile->closeFile();
    delete(outputFile);
    delete(voroOutputFile);

    /*calc time delete after*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}

void readAndWrite(){
    inFileMutex.lock();
    pair<string, int> line = voroOutputFile->readOneLine();
    if(line.first == ""){
        stop = true;
        return;
    }
    inFileMutex.unlock();

    WeinbergGraph<int> *graph = new WeinbergGraph<int>(line.first);
    WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
    wvector->calculate();

    outFileMutex.lock();
    outputFile->saveData(wvector->getCanonicalVector(), line.second);
    outFileMutex.unlock();
    delete(wvector);
    delete(graph);
}