#pragma once
#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class AdjGraph {
public:
    AdjGraph(int vertices);
    void addEdge(int src, int dest, int weight);
    vector<Edge> MST(int start);
private:
    int vertices;
    vector<vector<int>> adjMatrix; // ÁÚ½Ó¾ØÕó
};

