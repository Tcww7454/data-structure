#pragma once
#include<iostream>
using namespace std;

typedef struct Stacknode//����ڵ�Ĵ���
{
	int data;
	Stacknode* next;
}Stacknode, * LinkStackPrt;



struct LinkStack//�������һ���ṹ ������¼ջ����Ԫ�ظ��� 
{
	LinkStackPrt top;    // ջ��ָ�룬ָ��ջ��Ԫ��  
	int count = 0;         // ջ��Ԫ�ص�����  
};

bool InitStack(LinkStack* L);
void Push(LinkStack* L, int e);//ѹջ
bool Pop(LinkStack* L, int e);//��ջ
bool StackEmpty(LinkStack* L);//�ж�ջ�Ƿ�Ϊ��
void CreatStack(LinkStack* L, const int n);//����ջ
int Getcount(LinkStack* L);//��ȡջ��Ԫ�ظ���
bool DeleteStack(LinkStack* L);//���ջ


bool InitStack(LinkStack *L)
{

	L->top = nullptr;
	L->top->next = nullptr;
	return true;
}


void Push(LinkStack* L, int e)//ѹջ�ľ������
{
	LinkStackPrt p = new Stacknode;
	p->data = e;
	p->next = L->top;
	L->top = p;
	L->count++;
}


bool StackEmpty(LinkStack* L)//�ж�ջ�Ƿ�Ϊ��
{
	if (!L->top) return true;
	else return false;
}

bool Pop(LinkStack* L, int e)//��ջ
{
	LinkStackPrt p;
	if (StackEmpty(L))
	{
		cout << "error" << endl;
		return false;
	}
	p = L->top;
	e = L->top->data;
	L->top = L->top->next;
	L->count--;
	return true;
}

void CreatStack(LinkStack* L, const int n)//����һ��ջ
{
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		Push(L, input);

	}
}

int Getcount(LinkStack* L)
{
	return L->count;
}

bool DeleteStack(LinkStack* L)//���ջ
{
	if (!L->top)
	{
		cout << "error" << endl;
		return false;
	}
	Stacknode* q, * p = L->top;
	while (q=p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	q = NULL;
	p = NULL;
	L->top = NULL;
	return true;
}