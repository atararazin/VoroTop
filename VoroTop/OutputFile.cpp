#include "OutputFile.h"
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
        std::cout << "Caught " << excp << "unable to create file " << fileName << ".wvector" << std::endl;
        exit(-1);
    }
}


void OutputFile::writeTofile(std::string s) {
    file << s;
}

OutputFile::~OutputFile(){
    file.close();
}
