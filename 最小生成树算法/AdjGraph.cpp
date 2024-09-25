#include "AdjGraph.h"
#include"UnionFind.h"

AdjGraph::AdjGraph(int vertices)
{
    adjMatrix.resize(vertices, vector<int>(vertices, INT_MAX)); // 初始化为无穷大
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i][i] = 0; // 自己到自己的距离为0
    }
}

void AdjGraph::addEdge(int src, int dest, int weight)
{
    adjMatrix[src][dest] = weight;
    adjMatrix[dest][src] = weight;
}

vector<Edge> AdjGraph::MST(int start)
{
    vector<Edge> res;
    vector<Edge> edges;
    UnionFind uf(vertices);
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            edges.push_back({ i,j,adjMatrix[i][j] });
        }
    }
    sort(edges.begin(),edges.end(),[](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
        });
    int edgeCount = 0;
    int index = 0;
    while (edgeCount < vertices - 1) {
        Edge nextEdge = edges[index++];
        int x = uf.find(nextEdge.src);
        int y = uf.find(nextEdge.dest);
        if (x != y) {
            res.push_back(nextEdge);
            uf.unionSet(x, y);
            edgeCount++;
        }
    }

    return res;
}
