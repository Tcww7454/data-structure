#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
using namespace std;

typedef char Status;
constexpr char VISITED = '1';
constexpr char UNVISITED = '0';

// 此部分ChatGPT生成
struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    const std::vector<std::list<std::pair<int, int>>>& getAdjList() const;
    std::vector<Edge> getEdges() const;
    int getVerticesCount() const;
    void dfs(int start);
    void bfs(int start);
    vector<Edge> primMST(int start);
private:
    int vertices;
    std::vector<std::list<std::pair<int, int>>> adjList;
    void dfsUtil(int vertex, std::vector<bool>& visited);
};
