//
// Created by atara on 12/12/19.
//

#ifndef VOROTOP_CANONICALVECTOR_H
#define VOROTOP_CANONICALVECTOR_H
#include <vector>


class CanonicalVector {
public:
    std::vector<int> getVector();
    void addToVector(int num);
    void changeCurrValue(int index, int val);
    std::string compareToCode(int curr_num, int index);

private:
    std::vector<int> vector;
};


#endif //VOROTOP_CANONICALVECTOR_H
