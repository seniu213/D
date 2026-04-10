#ifndef DIJKSTRA_GRAF_H
#define DIJKSTRA_GRAF_H
#include <iostream>
#include <vector>
#include "Node.h"


class Graf{
private:
    std::vector<Node> nodes;

public:

    Graf(std::vector<Node> nodes){
        this->nodes = nodes;
    }


    Graf() = default;
    ~Graf() = default;





};










#endif //DIJKSTRA_GRAF_H
