#include "ArrayGraph.h"

ArrayGraph::ArrayGraph(int vertices)
{
    numVertices = vertices;
    adjacencyCount = 0;

    adjMatrix.resize(vertices, vector<Status>(vertices, DISCONNECTED));
}

void ArrayGraph::addEdge(int v, int w)
{
    if (v < 0 || v >= numVertices || w < 0 || w >= numVertices)
        throw out_of_range("Index out of range");

    adjMatrix[v][w] = CONNECTED;
    adjMatrix[w][v] = CONNECTED;
    adjacencyCount++;
}

vector<int> ArrayGraph::getAdjacent(int v) const
{
    vector<int>res;
    for (int i = 0; i < numVertices; ++i) {
        if (adjMatrix[v][i] == CONNECTED)
            res.push_back(i);
    }
    return res;
}

int ArrayGraph::getEdgesCount() const
{
    return adjacencyCount;
}

int ArrayGraph::getVerticesCount() const
{
    return numVertices;
}

void ArrayGraph::DFS(int start)
{
    if (start < 0 || start >= numVertices)
        throw out_of_range("Index out of range");
    vector<char> visited(numVertices, 0);
    stack<int> stk;
    stk.push(start);
    visited[start] = 1;

    while (!stk.empty()) {
        int top = stk.top();
        stk.pop();
        cout << top << " ";

        for (int adj : getAdjacent(top)) {  
            if (!visited[adj]) {
                stk.push(adj);
                visited[adj] = 1;
            }

        }
    }
}

void ArrayGraph::BFS(int start)
{
    if (start < 0 || start >= numVertices)
        throw out_of_range("Index out of range");
    vector<char> visited(numVertices, 0);
    queue<int> que;
    que.push(start);
    visited[start] = 1;

    while (!que.empty()){
        int front = que.front();
        que.pop();
        cout << front << " ";

        for (int adj : getAdjacent(front)) {
            if (!visited[adj]) {
                que.push(adj);
                visited[adj] = 1; 
            }
        }
    }
}
