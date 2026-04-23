#ifndef DEJKSTRA_KRAWEDZ_H
#define DEJKSTRA_KRAWEDZ_H
#include <iostream>


using namespace std;

class Wierzcholek;
class Krawedz {
public:
    Wierzcholek* do1 = nullptr;
    int koszt = 0;

    Krawedz(Wierzcholek *do1, int koszt) {
        this->koszt = koszt;
        this->do1 = do1;
    };

    Krawedz() = default;
    ~Krawedz() = default;

};



#endif //DEJKSTRA_KRAWEDZ_H