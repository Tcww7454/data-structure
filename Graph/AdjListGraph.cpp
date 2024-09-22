#include "AdjListGraph.h"

AdjListGraph::AdjListGraph(int vertices)
{
	numVertices = vertices;
	adjacencyCount = 0;
	adjList.resize(vertices);
}

void AdjListGraph::addEdge(int v, int w)
{
	if (v<0 || v>numVertices || w<0 || w>numVertices) {
		throw out_of_range("Index out of range");
	}

	for (int val : adjList[v]) {
		if (val == w)
			return;
	}

	adjList[v].push_back(w);
	adjList[w].push_back(v);
	adjacencyCount++;
}

vector<int> AdjListGraph::getAdjacent(int v) const
{
	vector<int> res;
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

// 深度优先遍历
void AdjListGraph::DFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw out_of_range("Index out of range");
	vector<char> visited(numVertices, 0);
	stack<int> stk;
	stk.push(start);
	visited[start] = true;

	while (!stk.empty()) {
		int top = stk.top();
		stk.pop();
		cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				stk.push(val);
				visited[val] = 1;
			}
		}
	}
}

// 广度优先遍历
void AdjListGraph::BFS(int start)
{
	if (start < 0 || start >= numVertices)
		throw out_of_range("Index out of range");
	vector<char> visited(numVertices, 0);
	queue<int> que;
	que.push(start);
	visited[start] = true;

	while (!que.empty()) {
		int top = que.front();
		que.pop();
		cout << top << " ";

		for (int val : adjList[top]) {
			if (!visited[val]) {
				que.push(val);
				visited[val] = 1;
			}
		}
	}
}
