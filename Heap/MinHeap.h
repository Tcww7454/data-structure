#pragma once
#include "Heap.h"
class MinHeap :
    public Heap
{
protected:
    void siftUp(int index) override;

    void siftDown(int index) override;

};

