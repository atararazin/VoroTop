//
// Created by atara on 2/17/20.
//

#ifndef VOROTOP_GRAPHSFILE_H
#define VOROTOP_GRAPHSFILE_H

#include <fstream>

using namespace std;

class GraphsFile {
public:
    GraphsFile(string line);
    pair<string, int> readOneLine();
    int getSize();
    ~GraphsFile();
private:
    fstream file;
    int upto = 0;
    int size = 0;

};


#endif //VOROTOP_GRAPHSFILE_H
