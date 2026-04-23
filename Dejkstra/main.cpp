#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Graf.h"
#include "Krawedz.h"
#include "Wierzcholek.h"

using namespace std;
const int INF = 1000000000;

bool parser(const string& filename, Graf& g) {
    ifstream file(filename);

    if (!file) {
        cout << "plik sie nie otworzyl\n";
        return false;
    }

    int n, start;
    file >> n >> start;
    string skipLine;
    getline(file, skipLine);

    g.w1.clear();
    g.d_start = start;
    g.w1.reserve(n);

    for (int i = 0; i < n; i++) {
        string name;
        getline(file, name);
        if (name.empty()) {
            i--;
            continue;
        }
        g.w1.emplace_back(name);
    }

    int a, b, w;
    while (file >> a >> b >> w) {
        g.w1[a].krawedzi.emplace_back(&g.w1[b], w);
        g.w1[b].krawedzi.emplace_back(&g.w1[a], w);
    }

    return true;
}

void dejkstra(Graf& g, int startIndex) {
    for (auto& v : g.w1) {
        v.koszt = INF;
        v.prev = nullptr;
        v.odwiedzony = false;
    }

    Wierzcholek* start = &g.w1[startIndex];
    start->koszt = 0;

    for (int i = 0; i < g.w1.size(); i++) {
        Wierzcholek* u = nullptr;
        int minKoszt = INF;

        for (auto& v : g.w1) {
            if (!v.odwiedzony && v.koszt < minKoszt) {
                minKoszt = v.koszt;
                u = &v;
            }
        }

        if (u == nullptr || u->koszt == INF) {
            break;
        }

        u->odwiedzony = true;

        for (auto& e : u->krawedzi) {
            Wierzcholek* v = e.do1;

            if (!v->odwiedzony && u->koszt + e.koszt < v->koszt) {
                v->koszt = u->koszt + e.koszt;
                v->prev = u;
            }
        }
    }

    for (auto& v : g.w1) {
        cout << start->name << "->" << v.name << ": ";

        vector<string> path;
        for (Wierzcholek* u = &v; u != nullptr; u = u->prev) {
            path.push_back(u->name);
        }

        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); i++) {
            if (i > 0) {
                cout << "-";
            }
            cout << path[i];
        }

        cout << " odleglosc: " << v.koszt << endl;
    }
}

int main() {
    Graf g;
    if (!parser("data.txt", g)) {
        return 1;
    }

    dejkstra(g, g.d_start);

    return 0;
}
