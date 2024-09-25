#ifndef DIJSTRA

#include"adjacency_matrix.h"
#include"prim.h"

class Dijstra:public PrimeGraph
{
    private:
        std::vector<int>dist;
    public:
       Dijstra(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges):
       PrimeGraph(vertices,edges),dist(vertices.size(),INT_MAX){}
       //这里的dist调用了vector的构造函数
       void dijstra(int start);
       void resetDist();
       int getDistanceTo(int vertex)const;
       void print();
};

#endif