//
// Created by atara on 9/23/19.
//

#ifndef VOROTOP_EDGE_H
#define VOROTOP_EDGE_H


class Edge {
    friend bool operator ==(Edge& a,  Edge& b) {
        if (a.u == b.u && a.v == b.v){
            return true;
        }
        return false;
    }


private:
    int u;
    int v;

public:
    Edge(int u, int v);
    Edge(const Edge&);
    int getV();
    int getU();
    //bool operator==(const Edge& edge);
    bool operator<(const Edge& other);
    void print();
};


#endif //VOROTOP_EDGE_H
