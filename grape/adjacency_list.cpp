#include<iostream>
#include<queue>
#include<stack>
#include"adjacency_list.h"

AdjListGraph::AdjListGraph(int vertices)
{
	numVertices = vertices;
	adjacencyCount = 0;
	adjList.resize(vertices);
}

void AdjListGraph::addEdge(int v, int w)
{
	if (v<0 || v>numVertices || w<0 || w>numVertices) {
		throw std::out_of_range("Index out of range");
	}

	for (int val : adjList[v]) {
		if (val == w)
			return;
	}

	adjList[v].push_back(w);
	adjList[w].push_back(v);
	adjacencyCount++;
}

std::vector<int> AdjListGraph::getAdjacent(int v) const
{
	std::vector<int> res;
	for (int val : adjList[v])
		res.push_back(val);
	return res;
}

int AdjListGraph::getEdgesCount() const
{
	return adjacencyCount;
}

int AdjListGraph::getVerticesCount() const
{
	return numVertices;
}

void AdjListGraph::DFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw std::out_of_range("Index out of range");
	std::vector<char> visited(numVertices, 0);
	std::stack<int> stk;
	stk.push(start);
	visited[start] = true;

	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		std::cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				stk.push(val);
				visited[val] = 1;
			}
		}
	}
}

void AdjListGraph::BFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw std::out_of_range("Index out of range");
	std::vector<char> visited(numVertices, 0);
	std::queue<int> que;
	que.push(start);
	visited[start] = true;

	while (!que.empty()) {
		int top = que.front();
		que.pop();
		std::cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				que.push(val);
				visited[val] = 1;
			}
		}
	}
}