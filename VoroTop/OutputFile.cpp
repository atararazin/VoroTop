//
// Created by atara on 12/15/19.
//

#include "OutputFile.h"
using namespace std;
/**
 * using the name given as input for the input file, create the output file of the same
 * name, but using .wvector.
 * @param fileName
 */
void OutputFile::createFile(std::string fileName) {
    std::string outFileName = fileName.substr(0, fileName.find("."));
    try{
        file.open(outFileName + ".wvector");
    }
    catch (char* excp){
        cout << "Caught " << excp << endl;
    }
}

/**
 * writes the values of the canonical vector into the file.
 * format: each vector gets its own line, starting and ending with "(" and ")".
 * each number is separated by a comma, followed by a space.
 * @param vec
 */
void OutputFile::saveData(std::vector<int>& vec, int upto) {
    //index++;
    //if(index >= upto){
        writeToFile(vec);
    //    writeWaitingToFile(upto + 1);
    //}
    //else{
    //    waitingQueue.insert({upto, vec});//[upto] = vec;
    //}

}

void OutputFile::writeWaitingToFile(int curr) {
    std::vector<int> found;
    while(waitingQueue.find(curr) != waitingQueue.end()){
        found = waitingQueue[curr];
        writeToFile(found);
        waitingQueue.erase(curr);
        curr++;
        index++;
    }
    //index--;
}

void OutputFile::writeToFile(std::vector<int> &vec) {
    string strForFile = "(";
    long n = vec.size();
    for(int i  = 0; i < n - 1; i++){
        strForFile.append(std::to_string(vec.at(i)) + ",");
    }
    strForFile.append(std::to_string(vec.at(n - 1)) + ")\n");
    file << strForFile;
}

void OutputFile::writeTofile(std::string s) {
    file << s;
}
std::ofstream* OutputFile::getFile() {
    return &file;
}
void OutputFile::closeFile() {
    this->file.close();
}

OutputFile::~OutputFile(){
    //file.close();
}
