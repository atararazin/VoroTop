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
    cout << "number of threads" << numberOfThreads << endl;
    if (numberOfThreads == 0) {
        numberOfThreads = 2;
    }
    ThreadPool pool(numberOfThreads);
    std::vector< std::future<string>> results;

    for(int i = 0; i < fileLen; ++i) {
        string line = voroOutputFile->readOneLine();
        results.emplace_back(
                pool.enqueue([i, line] {
                     return async_calculate(line);
                })
        );
    }

    for(auto && result: results){
        outputFile->writeTofile(result.get());
    }

    std::cout << std::endl;



    /*
    int numOfThreads = 2;

    int i = 0;
    while(i < fileLen/numOfThreads){

        pair<string, int> p1 = voroOutputFile->readOneLine();
        pair<string, int> p2 = voroOutputFile->readOneLine();
        //pair<string, int> p3 = voroOutputFile->readOneLine();

        //pair<string, int> p3 = voroOutputFile->readOneLine();
        //pair<string, int> p4 = voroOutputFile->readOneLine();
        //pair<string, int> p5 = voroOutputFile->readOneLine();

        std::future<std::string> res1 = std::async(std::launch::async, async_calculate, p1.first);
        std::future<std::string> res2 = std::async(std::launch::async, async_calculate, p2.first);
        //std::future<std::string> res3 = std::async(std::launch::async, async_calculate, p3.first);
        //std::future<std::string> res4 = std::async(std::launch::async, async_calculate, p4.first);
        //std::future<std::string> res5 = std::async(std::launch::async, async_calculate, p5.first);

        // Will block till data is available in future<std::string> object.
        std::string result1 = res1.get();
        std::string result2 = res2.get();
        //std::string result3 = res3.get();
        //std::string result4 = res4.get();
        //std::string result5 = res5.get();

        outputFile->writeTofile(result1);
        outputFile->writeTofile(result2);
        //outputFile->writeTofile(result3);
        //outputFile->writeTofile(result4);
        //outputFile->writeTofile(result5);

        i++;
    }
    i = i * numOfThreads;
    while(i < fileLen){
        pair<string, int> p1 = voroOutputFile->readOneLine();
        std::string res1 = async_calculate(p1.first);
        outputFile->writeTofile(res1);
        i++;
    }*/


    delete(voroOutputFile);
    delete(outputFile);
    auto end = system_clock::now();
    auto diff = duration_cast < microseconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Microseconds" << std::endl;
    std::cout << "                 = " << diff*1e-6 << " Seconds" << std::endl;


    return 0;
}