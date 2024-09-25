#pragma once
#include<vector>

class UnionFind {
public:
    UnionFind(int n);
    int find(int x);
    void unionSet(int x, int y);

private:
    std::vector<int> parent;
    std::vector<int> rank;
};
