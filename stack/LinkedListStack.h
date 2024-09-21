#ifndef QUEUE_L_H
#define QUEUE_L_H

class ListNode
{
    public:
        int value;
        ListNode*next;
        //这里的next指的是栈中下一个元素
        ListNode(int val=0):value(val),next(nullptr){};
};

class LinkedListStack//单向链表
{
    private:
        ListNode*stackTop;
        int stkSize;
        void destoryStack(ListNode*node);

    public:
        LinkedListStack();
        ~LinkedListStack();
        int size(){return stkSize;};
        bool isEmpty(){return stkSize==0;};
        void push(int num);
        int pop();
        int top();
        int *to_arr();//记得delete谢谢喵
};

#endif