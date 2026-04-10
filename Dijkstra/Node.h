#ifndef DIJKSTRA_NODE_H
#define DIJKSTRA_NODE_H
#include <iostream>
#include <vector>
#include "Krawedz.h"


class Node{
private:

    std::string name = "";
    std::vector<Krawedz> k;

public:

    void add_k(Krawedz a){
        k.push_back(a);
    }

    Node(std::string name){
        this->name = name;
    }

    ~Node() = default;

};

#endif //DIJKSTRA_NODE_H
