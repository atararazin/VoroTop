//
// Created by atara on 11/4/19.
//

#ifndef VOROTOP_WEINBERGVERTEX_H
#define VOROTOP_WEINBERGVERTEX_H


class WeinbergVertex : public Vertex {
private:
    int weinNum = -1;

public:
    bool old = false;
    int getWeinNum(int* i);
    Edge* getRightMostNeighbor();



};


#endif //VOROTOP_WEINBERGVERTEX_H
