#include "UnionFind.h"
// UnionFind.cpp
#include "UnionFind.h"

UnionFind::UnionFind(int n) : parent(n), rank(n, 0) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
}

int UnionFind::find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void UnionFind::unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY) return;

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    }
    else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    }
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}