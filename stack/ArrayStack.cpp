#include"ArrayStack.h"
#include<iostream>

stack_fixed::stack_fixed():top_index(-1){};

void stack_fixed::push(int num)
{
    if(top_index==Stack_Size-1)throw std::out_of_range("Stack is full, cannot push.");
    top_index++;
    stack_f[top_index]=num;
}

int stack_fixed::pop()
{
    if(top_index==-1)throw std::out_of_range("Stack is empty, cannot pop.");
    int temp=stack_f[top_index];
    top_index--;
    return temp;
}

int stack_fixed::top()const
{
    if(top_index==-1)throw std::out_of_range("Stack is empty, cannot accsee top");
    return stack_f[top_index];
}

stack_fixed::~stack_fixed(){}
