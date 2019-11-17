//
// Created by atara on 9/23/19.
//

#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>
#include "Graph.h"

bool otherDirIn(set<pair<int,int>> s, pair<int,int> p);
Edge* getRandEdge(vector<Edge*> edges, Vertex* v);
Face* findFace(vector<Face*> vectoroffaces, std::pair<int,int> p);

void Graph::create(string faces) {
    this->getFaces(faces);
    this->getVertices();
    this->getEdges();
    //this->assignEdgesToVertices();
}




bool otherDirIn(set<pair <int,int>> s, pair <int,int> p) {
    pair<int,int> otherDir(p.second, p.first);
    return(s.find(otherDir) != s.end());
}


/*void Graph::assignEdgesToVertices() {
    std::vector<Vertex*>::iterator it;
    for(Edge* e : this->edges){
        int u = e->getEdge().first;
        vertices.at(u)->addEdge(e);
        int v = e->getEdge().second;
        vertices.at(v)->addEdge(e);
    }

    //printing//
    for(Vertex* v : vertices){
        cout << v->data << ":" << endl;
        for(Edge* e : v->getEdges()){
            e->print();
        }

    }
}*/

/*assigns the list of edges to each vertices, sorted in a counter-clockwise manner*/
void Graph::assignEdgesToVertices() {
    std::vector<int>::iterator it;
    std::vector<Edge*>::iterator edgeIter;

    for(Vertex* v: vertices) {
        cout << "\ncurrent vertex:" << v->data << endl;
        Edge *e = getRandEdge(this->edges, v);
        //v->addEdge(e);
        std::pair<int,int> pe(e->edge);
        do{
            Face* face = findFace(this->faces,pe);
            if(face != NULL){
                it = std::find(face->nodes.begin(), face->nodes.end(), pe.first);
                int pos = it - face->nodes.begin();
                int size = face->nodes.size();
                int next = (pos+1) % size;
                if(face->nodes.at(next) == pe.second){
                    int newPos = ((pos-1) % size + size)%size;
                    std::pair<int,int> p1(face->nodes.at(newPos), v->data);
                    std::pair<int,int> p2(v->data, face->nodes.at(newPos));

                    Edge e1(p1);
                    auto counter = std::find_if (edges.begin(),
                                                 edges.end(),
                                                 [&e1](const Edge *f)->bool
                                                 { return (f->edge == e1.edge) ||
                                                          (f->edge.first == e1.edge.second
                                                           && f->edge.second == e1.edge.first);}
                    );
                    int posEdge = counter - edges.begin();
                    Edge* edge = edges.at(posEdge);
                    v->addEdge(edge);
                    pe = p2;

                }
            }
        }while(pe != e->edge);

        printf("the edges:\n");
        v->printEdges(v->getEdges());
            }

        }

Edge* getRandEdge(vector<Edge*> edges, Vertex* v){
    for(Edge* e : edges){
        if(e->getEdge().first == v->data || e->getEdge().first == v->data){
            return e;
        }
    }
}

Face* findFace(vector<Face*> vectoroffaces, std::pair<int,int> p){
    std::vector<int>::iterator it;
    for (Face *face: vectoroffaces) {
        int size = face->nodes.size();
        it = std::find(face->nodes.begin(), face->nodes.end(), p.first);
        if (it != face->nodes.end()) {
            int pos = it - face->nodes.begin();
            int next = (pos + 1) % size;
            if (face->nodes.at(next) == p.second) {
                return face;
            }
        }
    }
    return NULL;
}




Graph::~Graph() {
    for(Edge* e: edges){
        delete(e);
    }

    for(Vertex* vertex: vertices){
        delete(vertex);
    }

    for(Face* f : faces){
        delete(f);
    }
    delete(this);
}