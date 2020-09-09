#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include "Voro++/RunVoro.h"
#include "Graph/FacesToGraph.h"
#include "WeinbergAlgorithm/WeinbergVector.h"
#include "OutputFile.h"
#include "ThreadPool.h"

using namespace std;
std::string async_calculate(std::string recvdData);




OutputFile *outputFile;
VoroOutFile *voroOutputFile;

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

int main(int argc, char *argv[])
{
    outputFile = new OutputFile();
    outputFile->createFile("graphs");
    voroOutputFile = new VoroOutFile(argv[1]);

    int fileLen = voroOutputFile->getSize();

    // This returns the number of threads supported by the system. If the
    // function can't figure out this information, it returns 0. 0 is not good,
    // so we create at least 2
    auto numberOfThreads = std::thread::hardware_concurrency();
    if (numberOfThreads == 0) {
        numberOfThreads = 2;
    }
    ThreadPool* pool = new ThreadPool(8);
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
    return 0;
}