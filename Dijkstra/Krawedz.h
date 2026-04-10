#ifndef DIJKSTRA_KRAWEDZ_H
#define DIJKSTRA_KRAWEDZ_H
#include <iostream>
#include "Node.h"

class Krawedz{
private:

    Node* a = nullptr;
    int w = 0;

public:

    Krawedz(Node* a, int w){
        this->a = a;
        this->w = w;
    }

    ~Krawedz() = default;



};

#endif //DIJKSTRA_KRAWEDZ_H
