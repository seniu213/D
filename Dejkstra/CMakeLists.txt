cmake_minimum_required(VERSION 4.1)
project(Dejkstra)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dejkstra main.cpp
        Wierzcholek.h
        Krawedz.h
        Graf.h)
