#include"kruskal.h"

Kruskal::Kruskal(int val)
{
    V=val;
}

void Kruskal::addEdge(int s,int d,int w)
{
    edges.push_back({s,d,w});
}

int Kruskal::find(int parent[],int i)
{
    if (parent[i] == -1)
            return i;
    return find(parent, parent[i]);
}

void Kruskal::unionSet(int parent[],int x,int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void Kruskal::kruskalMST()
{
    std::sort(edges.begin(),edges.end(),[](Edge a,Edge b)
    {
        return a.weight<b.weight;
    });

    int *parent=new int [V];
    std::fill(parent,parent+V,-1);

    std::cout << "Edges in the Minimum Spanning Tree:\n";

        for (const auto& edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            // 如果两个顶点不属于同一个并查集，则加入该边
            if (x != y) {
                std::cout << "Edge: " << edge.src << " - " << edge.dest << " | Weight: " << edge.weight << std::endl;
                unionSet(parent, x, y);
            }
        }

        // 释放动态数组
        delete[] parent;
}