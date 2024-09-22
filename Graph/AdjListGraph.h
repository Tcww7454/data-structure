#pragma once
#include "Graph.h"
class AdjListGraph :
    public Graph
{
private:
    int numVertices; // ¶¥µãÊý
    int adjacencyCount; // ±ßÊý
    vector<list<int>>adjMatrix;
public:
    AdjListGraph(int vertices);

    void addEdge(int v, int w)override;

    vector<int> getAdjacent(int v)const override;

    int getEdgesCount()const override;

    int getVerticesCount()const override;

    void DFS(int start) override;

    void BFS(int start) override;
};

