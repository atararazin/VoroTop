//
// Created by atara on 2/17/20.
//

#ifndef VOROTOP_GRAPHSFILE_H
#define VOROTOP_GRAPHSFILE_H

#include <fstream>
#include <mutex>
#include <future>

using namespace std;

class GraphsFile {
public:
    GraphsFile(string line);
    string readOneLine();
    int getSize();
    ~GraphsFile();
private:
    fstream file;
    int size = 0;

};


#endif //VOROTOP_GRAPHSFILE_H
