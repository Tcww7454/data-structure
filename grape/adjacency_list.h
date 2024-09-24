#ifndef ADJ_LIAT_H
#define ADJ_LIST_H

#include<list>
#include<vector>
// #include<map>

// class adj_list
// {
//     private:
//         int vertices;
//         std::vector<std::list<int>>adjlist;
//         std::map<int,int>vertexIndex;
//     public:
//         adj_list(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges);
//         void addedge(int src,int dest);//添加从src到dest的边
//         void print();
// };

class AdjListGraph
{
private:
    int numVertices; // ¶¥µãÊý
    int adjacencyCount; // ±ßÊý
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