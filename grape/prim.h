#ifndef PRIM_H_
#define PRIM_H_

//由于前俩和都没有加权，省的麻烦直接再写一个，虽然还是没有用abc
//prim算法，适合
#include <iostream>
#include <vector>
#include <climits>
#include<queue>
#include<unordered_map>
#include <algorithm>  // for std::find
#include <iterator>   // for std::distance
#include"adjacency_matrix.h"

class PrimeGraph:public GraphAdjMat
{
    public:
        PrimeGraph(const std::vector<int> &vertices, const std::vector<std::vector<int>>&edges);
        //原本的矩阵为无权的，简单修改为有权的，直接虚了
        void addEdge (int u,int v,int weight);
        void generateMST(int start);

};

#endif