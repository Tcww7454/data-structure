#pragma once

#include<vector>
#include<stack>
#include<iostream>
#include<queue>
#include<list>
#include <stdexcept>
using namespace std;

// 无向图 有向图也是类似的

class Graph {
public:
	virtual ~Graph() = default;

	// 添加边
	virtual void addEdge(int v, int w) = 0;

	// 获取与 v 相邻的所有顶点
	virtual vector<int> getAdjacent(int v) const = 0;

	// 获取顶点数量
	virtual int getVerticesCount()const = 0;

	// 获取边的数量
	virtual int getEdgesCount()const = 0;

	// 深度优先遍历
	virtual void DFS(int start) = 0;

	// 广度优先遍历
	virtual void BFS(int start) = 0;
};