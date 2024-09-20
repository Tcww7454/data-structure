#include<iostream>
#include"LinkedListStack.h"
#include"ArrayStack.h"

int main()
{
    //std::cout<<1<<std::endl;

    // //测试成功
    // {
    // LinkedListStack stack_first;
    // //1为空，0为非空
    // std::cout<<stack_first.isEmpty()<<std::endl;//1

    // stack_first.push(1);
    // std::cout<<stack_first.isEmpty()<<std::endl;//0
    // std::cout<<stack_first.top()<<std::endl;//1

    // stack_first.pop();
    // std::cout<<stack_first.isEmpty()<<std::endl;//1
    // std::cout<<stack_first.top()<<std::endl;//栈空，报错提醒
    // }

    //数组栈测试
    {
    stack_fixed stack_first;
    //1为空，0为非空
    std::cout<<stack_first.isEmpty()<<std::endl;//1

    stack_first.push(1);
    std::cout<<stack_first.isEmpty()<<std::endl;//0
    std::cout<<stack_first.top()<<std::endl;//1

    stack_first.pop();
    std::cout<<stack_first.isEmpty()<<std::endl;//1
    std::cout<<stack_first.top()<<std::endl;//栈空，报错提醒
    }

    
    return 0;
}