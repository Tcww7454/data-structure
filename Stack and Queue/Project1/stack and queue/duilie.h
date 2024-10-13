#pragma once
#include<iostream>
using namespace std;

struct Qnode {};//����Ľڵ�

struct LinkQueue {};//�������ͷָ���βָ��

void InitQueue(LinkQueue& Q);//�Զ��еĳ�ʼ������
void InsterQueue(LinkQueue& Q, int e);//����
void CreatQueue(LinkQueue& Q, int n);//��������
bool OutQueue(LinkQueue& Q);//����

int main()
{

}

struct Qnode//����Ľڵ�
{
    int data = 0;
    Qnode* next;
};

struct LinkQueue//�������ͷָ���βָ��
{
    Qnode* front;
    Qnode* rear;
};


void InitQueue(LinkQueue& Q)//���еĳ�ʼ��
{
    Q.front = Q.rear = new Qnode;
    Q.front->data = 0;
    Q.rear->next = nullptr;
}


void InsterQueue(LinkQueue& Q, int e)//����
{
    Qnode* p = new Qnode;
    p->data = e;
    p->next = nullptr;
    Q.rear->next = p;
    Q.rear = p;
    Q.front->data++;
}

void CreatQueue(LinkQueue& Q, int n)//��������
{
    int input;
    for (int i = 0; i < n; i++)

    {
        cin >> input;
        InsterQueue(Q, input);
    }
}

bool OutQueue(LinkQueue& Q)//����
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