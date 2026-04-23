#ifndef DEJKSTRA_GRAF_H
#define DEJKSTRA_GRAF_H

#include <iostream>
#include "Wierzcholek.h"
using namespace std;

class Graf {
    public:
    vector<Wierzcholek> w1 = vector<Wierzcholek>() ;
    int d_start = 0;

    Graf(vector<Wierzcholek> w1, int start) {
        this->w1 = w1;
        this->d_start = start;
    } ;



    Graf() = default;
    ~Graf() = default;
};



#endif //DEJKSTRA_GRAF_H