#pragma once
#include<iostream>
using namespace std;

#define n 100

struct SqQueue
{
	int* data;
	int front;
	int rear;
};

bool IsEmpty(SqQueue& Q);//判断队列是否为空

bool InitQueue(SqQueue& Q);//顺序队列的初始化

bool IsFull(SqQueue& Q);//判断是否满队

bool InsterQueue(SqQueue& Q, int e);//进队

bool OutQueue(SqQueue& Q, int e);//出队




bool IsEmpty(SqQueue& Q)//判断是否空队
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool IsFull(SqQueue& Q)//判断是否满队
{
	if (Q.rear == n)
	{
		return false;
	}
	return true;
}

bool InitQueue(SqQueue& Q)//顺序队列的初始化
{
	Q.data = new int[n];
	Q.front = Q.rear = 0;
	if (!Q.data)
	{
		cout << "error" << endl;
		return false;
	}
	Q.front = Q.rear = 0;
	return true;
}

bool InsterQueue(SqQueue& Q, int e)//入队
{
	if (IsFull(Q))
	{
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear++;
	return true;
}

bool OutQueue(SqQueue& Q, int e)//出队
{
	if (IsEmpty(Q))
	{
		cout << "空队" << endl;
		return false;
	}
	e = Q.data[Q.front];
	Q.front++;
	return true;
}

