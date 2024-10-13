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

bool IsEmpty(SqQueue& Q);//�ж϶����Ƿ�Ϊ��

bool InitQueue(SqQueue& Q);//˳����еĳ�ʼ��

bool IsFull(SqQueue& Q);//�ж��Ƿ�����

bool InsterQueue(SqQueue& Q, int e);//����

bool OutQueue(SqQueue& Q, int e);//����




bool IsEmpty(SqQueue& Q)//�ж��Ƿ�ն�
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool IsFull(SqQueue& Q)//�ж��Ƿ�����
{
	if (Q.rear == n)
	{
		return false;
	}
	return true;
}

bool InitQueue(SqQueue& Q)//˳����еĳ�ʼ��
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

bool InsterQueue(SqQueue& Q, int e)//���
{
	if (IsFull(Q))
	{
		return false;
	}
	Q.data[Q.rear] = e;
	Q.rear++;
	return true;
}

bool OutQueue(SqQueue& Q, int e)//����
{
	if (IsEmpty(Q))
	{
		cout << "�ն�" << endl;
		return false;
	}
	e = Q.data[Q.front];
	Q.front++;
	return true;
}

