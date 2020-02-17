//
// Created by atara on 2/17/20.
//

#ifndef VOROTOP_GRAPHSFILE_H
#define VOROTOP_GRAPHSFILE_H

#include <fstream>

using namespace std;

class GraphsFile {
public:
    GraphsFile(string filePath);
    bool endOfFile = false;
    string readOneLine();
    ~GraphsFile();

private:
    fstream file;


};


#endif //VOROTOP_GRAPHSFILE_H
