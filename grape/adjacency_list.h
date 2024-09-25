#ifndef ADJ_LIAT_H
#define ADJ_LIST_H

#include<list>
#include<vector>

class AdjListGraph
{
private:
    int numVertices; 
    int adjacencyCount; 
    std::vector<std::list<int>>adjList;
public:
    AdjListGraph(int vertices);

    void addEdge(int v, int w);

    std::vector<int> getAdjacent(int v)const;

    int getEdgesCount()const;

    int getVerticesCount()const;

    void DFS(int start);

    void BFS(int start);
};


#endif