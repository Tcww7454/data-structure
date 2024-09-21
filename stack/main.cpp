#include<iostream>
#include"LinkedListStack.h"
#include"ArrayStack.h"

int main()
{
    //std::cout<<1<<std::endl;

    //测试成功
    {
    LinkedListStack stack_first;
    //1为空，0为非空
    std::cout<<stack_first.isEmpty()<<std::endl;//1

    stack_first.push(1);
    std::cout<<stack_first.isEmpty()<<std::endl;//0
    std::cout<<stack_first.top()<<std::endl;//1

    stack_first.pop();
    std::cout<<stack_first.isEmpty()<<std::endl;//1
    //std::cout<<stack_first.top()<<std::endl;//栈空，报错提醒
    //不使用try块会导致出现异常直接结束，找措找了几十分钟，我是fvv
    try {
    // 可能会抛出异常的代码
    std::cout << stack_first.top() << std::endl; // 可能抛出异常
    } catch (const std::out_of_range& e) {
    // 处理异常
    std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    stack_first.push(1);
    stack_first.push(2);
    stack_first.push(3);
    stack_first.push(4);
    stack_first.push(5);
     int *stack_to_arr = stack_first.to_arr();
    if (stack_to_arr) {
        int size = stack_first.size();
        for (int i = 0; i < size; i++) {
            std::cout << stack_to_arr[i] << "\t";
        }
        std::cout<<std::endl;
        delete[] stack_to_arr; // 释放内存
    } else {
        std::cout << "Stack is empty, nothing to display." << std::endl;
    }
    }
    // //数组栈测试
    // {
    // stack_fixed stack_first;
    // //1为空，0为非空
    // std::cout<<stack_first.isEmpty()<<std::endl;//1
    // stack_first.push(1);
    // std::cout<<stack_first.isEmpty()<<std::endl;//0
    // std::cout<<stack_first.top()<<std::endl;//1
    // stack_first.pop();
    // std::cout<<stack_first.isEmpty()<<std::endl;//1
    // std::cout<<stack_first.top()<<std::endl;//栈空，报错提醒
    // }
    
    return 0;
}