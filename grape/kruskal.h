#ifndef KRUSKAL_H
#define KRUSKAL_H
#include<vector>
#include<algorithm>
#include<iostream>
class Edge
{
    public:
        int src,dest,weight;
        Edge(int s,int d,int w):src(s),dest(d),weight(w){}
};

class Kruskal
{
    private:
        int V;//节点数
        std::vector<Edge>edges;
        int find(int parent[],int i);//并查集查找
        void unionSet(int parent[],int x,int y);//并查集合并
    public:
        void addEdge(int s,int d,int w);
        void kruskalMST();
        Kruskal(int val=0);
};

#endif