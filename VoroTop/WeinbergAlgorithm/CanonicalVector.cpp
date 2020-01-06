//
// Created by atara on 12/12/19.
//

#include <string>
#include <iostream>
#include "CanonicalVector.h"

std::vector<int> CanonicalVector::getVector() {
    return this->vector;
}

void CanonicalVector::addToVector(int num) {
    vector.push_back(num);
}

void CanonicalVector::changeCurrValue(int val) {
    vector[index] = val;
}

void CanonicalVector::incrementIndex() {
    index++;
}

void CanonicalVector::clear() {
    vector.clear();
    resetIndex();
}
/**
 * index starts at 2 because 0 and 1 are for the first edge's vertices
 */
void CanonicalVector::resetIndex() {
    index = 2;
}


/**
 * compares the current Weinberg code to the code in the same index in the canonical vector.
 * @param i - the current vertex's Weinberg value
 * @return bigger, smaller or equal, depending on the result
 */
std::string CanonicalVector::compareToCode(int curr_num) {
    if(curr_num > vector[index]){
        return "bigger";
    }
    else if(curr_num == vector[index]){
        return "equal";
    }
    else{
        return "smaller";
    }
}
