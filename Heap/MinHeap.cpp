#include "MinHeap.h"

void MinHeap::siftUp(int index)
{
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (heap[index] < heap[parent])
			swap(heap[index], heap[parent]);
		index = parent;
	}
}

void MinHeap::siftDown(int index)
{
	int leftChild, rightChild, largest, size = heap.size();
	while ((leftChild = 2 * index + 1) < size) {
		largest = index;
		rightChild = leftChild + 1;
		if (heap[leftChild] < heap[largest])
			largest = leftChild;
		if (heap[rightChild]<size && heap[rightChild]<heap[largest])
			largest = rightChild;
		if (largest == index)
			break;
		swap(heap[index], heap[largest]);
		index = largest;
	}
}
