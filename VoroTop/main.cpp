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
#include "Voro++/ValidityChecker.h"

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


int main(int argc, char *argv[]) {
    auto start = high_resolution_clock::now();
    printf("running the program\n");
    fstream file;
    string inputFileName = argv[1];
    //file.open(inputFileName);
    //string str;
    //fstream* fref = &file;
    ValidityChecker* validityChecker = new ValidityChecker(inputFileName);
    if(!validityChecker->check()){
        return 0;
    }


    Input* input = new Input(inputFileName);
    cout << input->getInputString() << endl;
    file.close();
    VoronoiCell* voronoiCell = new VoronoiCell();
    voronoiCell->calcVorCell(input);

/*
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
*/
    //for calculating time - delete after
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "microseconds" << endl;
    cout << duration.count() * 0.000001 << "seconds" << endl;
}


/*
using namespace std::chrono;
OutputFile *outputFile;
GraphsFile *voroOutputFile;

std::string async_calculate(std::string recvdData)
{
    WeinbergGraph<int> *graph = new WeinbergGraph<int>(recvdData);
    WeinbergVector<int>* wvector = new WeinbergVector<int>(graph);
    wvector->calculate();
    string result = wvector->getString();
    delete(graph);
    delete(wvector);
    return result;
}

int main()
{
    printf("running\n");
    auto start = high_resolution_clock::now();

    outputFile = new OutputFile();
    outputFile->createFile("graphs");
    voroOutputFile = new GraphsFile("/home/atara/VoroTop/tests/graphs100");
    //voroOutputFile = new GraphsFile("/home/atara/Downloads/big_data-1 (1)/PV-1000000-0-1.graphs");
    int fileLen = voroOutputFile->getSize();

    // This returns the number of threads supported by the system. If the
    // function can't figure out this information, it returns 0. 0 is not good,
    // so we create at least 2
    auto numberOfThreads = std::thread::hardware_concurrency();
    if (numberOfThreads == 0) {
        numberOfThreads = 2;
    }
    ThreadPool* pool = new ThreadPool(numberOfThreads);
    std::vector< std::future<string>> results;

    for(int i = 0; i < fileLen; ++i) {
        string line = voroOutputFile->readOneLine();
        results.emplace_back(
                pool->enqueue([i, line] {
                     return async_calculate(line);
                })
        );
    }

    for(auto && result: results){
        outputFile->writeTofile(result.get());
    }


    delete(pool);
    delete(voroOutputFile);
    delete(outputFile);

    calculates time - delete after
    auto end = system_clock::now();
    auto diff = duration_cast < microseconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Microseconds" << std::endl;
    std::cout << "                 = " << diff*1e-6 << " Seconds" << std::endl;
    return 0;
}*/