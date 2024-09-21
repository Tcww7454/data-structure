#pragma once
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Heap {
public:
	void insert(int value) {
		heap.push_back(value);
		siftUp(size() - 1);
	}

	void remove() {
		if (size() == 0) return;
		swap(heap[0], heap[size() - 1]);
		heap.pop_back();
		siftDown(0);
	}

	int getTop() {
		if (heap.size() == 0)
			throw runtime_error("Heap is empty");
	}

	int size() {
		return heap.size();
	}

	void printHeap() {
		for (int item : heap)
			cout << item << " ";
		cout << endl;
	}

protected:
	vector<int> heap;

	virtual void siftUp(int index) = 0;

	virtual void siftDown(int index) = 0;
};