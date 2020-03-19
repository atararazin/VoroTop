//
// Created by atara on 3/12/20.
//

#include <sstream>
#include <vector>
#include "ValidityChecker.h"

ValidityChecker::ValidityChecker(std::string fileName) {
    file.open(fileName);
}

bool ValidityChecker::check(){
    if(!checkTimeStep()){
        return false;
    }
    if(!checkNumAtoms()){
        return false;
    }
    if(!checkBoxBound()){
        return false;
    }
    if(!checkAtoms()){
        return false;
    }

    return true;
}

bool ValidityChecker::checkTimeStep() {
    std::string line;
    getline(file, line);
    if(line != "ITEM: TIMESTEP"){
        return false;
    }
    getline(file, line);
    try{
        std::stoi(line);
    }
    catch(...){
        std::cout << "VoroTop: TIMESTEP: not a number" << std::endl;
        return false;
    }
    if(std::stoi(line) < 0){
        std::cout << "VoroTop: TIMESTEP: negative number" << std::endl;
        return false;
    }
    return true;
}

bool ValidityChecker::checkNumAtoms() {
    std::string line;
    getline(file,line);
    if(line != "ITEM: NUMBER OF ATOMS"){
        return false;
    }
    getline(file, line);
    try{
        std::stoi(line);
    }
    catch(...){
        std::cout << "VoroTop: NUMBER OF ATOMS: not a number" << std::endl;
        return false;
    }
    if(std::stoi(line) < 0){
        std::cout << "VoroTop: NUMBER OF ATOMS: negative number" << std::endl;
        return false;
    }
    return true;
}

bool ValidityChecker::checkBoxBound() {
    std::string line;
    getline(file,line);
    if(line != "ITEM: BOX BOUNDS pp pp pp"){
        return false;
    }
    for(int i = 0; i < 3; i++){
        getline(file,line);
        std::vector<std::string> result;
        std::istringstream iss(line);
        for(std::string s; iss >> s; )
            result.push_back(s);
        if(result.size() != 2){
            std::cout << "VoroTop: BOX BOUNDS: not 2 numbers per line" << std::endl;
            return false;
        }
        for(std::string string: result){
            try{
                std::stof(string);
            }
            catch(...){
                std::cout << "VoroTop: BOX BOUNDS: not a number. " <<  "Error: " << string << std::endl;
                return false;
            }
        }

    }

    return true;
}

bool ValidityChecker::checkAtoms() {
    std::string line;
    getline(file,line);
    if(line != "ITEM: ATOMS id type x y z "){
        std:: cout << "VoroTop: missing atoms" << std::endl;
        return false;
    }
    while(getline(file,line)){
        std::vector<std::string> result;
        std::istringstream iss(line);
        for(std::string s; iss >> s; )
            result.push_back(s);
        if(result.size() != 5){
            std::cout << "VoroTop: ATOMS: not 5 numbers per line" << std::endl;
            return false;
        }
        for(std::string string: result){
            try{
                std::stof(string);
            }
            catch(...){
                std::cout << "VoroTop: ATOMS: not a number. " <<  "Error: " << string << std::endl;
                return false;
            }
        }
    }

    file.close();
    return true;
}