//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


class WeinbergVertex : Vertex {
private:
    int weinNum = -1;

public:
    bool old = false;
    int getWeinNum(int* i);


};


#endif //VOROTOP_WEINBERGVERTEX_H
