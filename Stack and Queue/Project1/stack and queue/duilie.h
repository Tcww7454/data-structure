#pragma once
#include<iostream>
using namespace std;

struct Qnode {};//具体的节点

struct LinkQueue {};//抽象出来头指针和尾指针

void InitQueue(LinkQueue& Q);//对队列的初始化操作
void InsterQueue(LinkQueue& Q, int e);//进队
void CreatQueue(LinkQueue& Q, int n);//创建队列
bool OutQueue(LinkQueue& Q);//出队

int main()
{

}

struct Qnode//具体的节点
{
    int data = 0;
    Qnode* next;
};

struct LinkQueue//抽象出来头指针和尾指针
{
    Qnode* front;
    Qnode* rear;
};


void InitQueue(LinkQueue& Q)//队列的初始化
{
    Q.front = Q.rear = new Qnode;
    Q.front->data = 0;
    Q.rear->next = nullptr;
}


void InsterQueue(LinkQueue& Q, int e)//进队
{
    Qnode* p = new Qnode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    Q.front->data++;
}

void CreatQueue(LinkQueue& Q, int n)//创建队列
{
    int input;
    for (int i = 0; i < n; i++)

    {
        cin >> input;
        InsterQueue(Q, input);
    }
}

bool OutQueue(LinkQueue& Q)//出队
{
    if (!Q.front->next)
    {
        cout << "error" << endl;
        return false;
    }
    else
    {
        Qnode* p = new Qnode;
        p = Q.front->next;
        Q.front->next = p->next;
        delete p;
        Q.front->data--;
    }
}