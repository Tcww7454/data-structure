#pragma once

#include<vector>
#include<stack>
#include<iostream>
#include<queue>
#include<list>
#include <stdexcept>
using namespace std;

// ����ͼ ����ͼҲ�����Ƶ�

class Graph {
public:
	virtual ~Graph() = default;

	// ��ӱ�
	virtual void addEdge(int v, int w) = 0;

	// ��ȡ�� v ���ڵ����ж���
	virtual vector<int> getAdjacent(int v) const = 0;

	// ��ȡ��������
	virtual int getVerticesCount()const = 0;

	// ��ȡ�ߵ�����
	virtual int getEdgesCount()const = 0;

	// ������ȱ���
	virtual void DFS(int start) = 0;

	// ������ȱ���
	virtual void BFS(int start) = 0;
};