#include"MaxHeap.h"
#include"MinHeap.h"

int main() {
	Heap* heap = new MinHeap();

	heap->insert(1);
	heap->insert(7);
	heap->insert(3);
	heap->insert(0);
	heap->insert(6);

	heap->printHeap();
}