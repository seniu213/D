#ifndef DEJKSTRA_WIERZCHOLEK_H
#define DEJKSTRA_WIERZCHOLEK_H

#include <iostream>
#include <vector>
#include "Krawedz.h"
using namespace std;


class Wierzcholek {
public:
     string name = "";
     Wierzcholek *prev = nullptr;
     vector<Krawedz> krawedzi = vector<Krawedz>();
     bool odwiedzony = false;
     int koszt = 1000000000;

    Wierzcholek(const string name) {
        this->name = name;
    };
    Wierzcholek() = default;

    ~Wierzcholek() = default;

};

#endif //DEJKSTRA_WIERZCHOLEK_H
