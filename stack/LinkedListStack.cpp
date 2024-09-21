#include"LinkedListStack.h"
#include<iostream>
LinkedListStack::LinkedListStack()
{
    stkSize=0;
    stackTop=nullptr;
}

LinkedListStack::~LinkedListStack()
{
    destoryStack(stackTop);
}

void LinkedListStack::destoryStack(ListNode*node)
{
    while (node != nullptr) {
        ListNode* next = node->next;
        delete node;  
        node = next;
    }
}

void LinkedListStack::push(int num)
{
    ListNode* node=new ListNode(num);
    node->next=stackTop;
    stackTop=node;
    stkSize++;
}

int LinkedListStack::pop()
{
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty, cannot pop.");
    }
    int num=stackTop->value;
    ListNode*node=stackTop;
    stackTop=node->next;
    delete node;
    stkSize--;
    return num;
}

int LinkedListStack::top()
{
     if (isEmpty()) {
        throw std::out_of_range("Stack is empty, cannot access top.");
    }
    return stackTop->value;
}

int *LinkedListStack::to_arr()
{   
    if(stkSize==0) return nullptr;
    int *arr=new int [stkSize];
    ListNode *stack_top=stackTop;
    for(int i=stkSize-1;i>=0;i--)
    {
        arr[i]=stack_top->value;
        stack_top=stack_top->next;
    }
    return arr;
}