#pragma once
#include"Graph.h"

enum Status {
    DISCONNECTED,
    CONNECTED
};

// �ڽӾ���ʵ��
class ArrayGraph :
    public Graph
{
private:
    int numVertices; // ������
    int adjacencyCount; // ����
    vector<vector<Status>>adjMatrix;
public:
    ArrayGraph(int vertices);

    void addEdge(int v, int w)override;

    vector<int> getAdjacent(int v)const override;

    int getEdgesCount()const override;

    int getVerticesCount()const override;

    void DFS(int start) override;

    void BFS(int start) override;
};

