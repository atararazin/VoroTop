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
#include "ThreadPool.h"
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



#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
using namespace std::chrono;
OutputFile *outputFile;
GraphsFile *voroOutputFile;

std::string async_calculate(std::string recvdData)
{
    WeinbergGraph<int> *graph = new WeinbergGraph<int>(recvdData);
    WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
    wvector->calculate();
    return wvector->getString();
}

int main()
{
    printf("running\n");
    auto start = high_resolution_clock::now();

    outputFile = new OutputFile();
    outputFile->createFile("graphs");
    voroOutputFile = new GraphsFile("/home/atara/VoroTop/tests/graphs1");
    int fileLen = voroOutputFile->getSize();
    int numOfThreads = 4;

    int i = 0;
    while(i < fileLen/numOfThreads){

        pair<string, int> p1 = voroOutputFile->readOneLine();
        pair<string, int> p2 = voroOutputFile->readOneLine();
        pair<string, int> p3 = voroOutputFile->readOneLine();
        pair<string, int> p4 = voroOutputFile->readOneLine();

        std::future<std::string> res1 = std::async(std::launch::async, async_calculate, p1.first);
        std::future<std::string> res2 = std::async(std::launch::async, async_calculate, p2.first);
        std::future<std::string> res3 = std::async(std::launch::async, async_calculate, p3.first);
        std::future<std::string> res4 = std::async(std::launch::async, async_calculate, p4.first);

        // Will block till data is available in future<std::string> object.
        std::string result1 = res1.get();
        std::string result2 = res2.get();
        std::string result3 = res3.get();
        std::string result4 = res4.get();
        //std::cout << "Data = " << result1 << std::endl;
        //std::cout << "Data = " << result2 << std::endl;
        outputFile->writeTofile(result1);
        outputFile->writeTofile(result2);
        outputFile->writeTofile(result3);
        outputFile->writeTofile(result4);

        i++;
    }
    delete(voroOutputFile);
    delete(outputFile);
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;


    return 0;
}