#pragma once
#include<iostream>
using namespace std;

typedef struct Stacknode//具体节点的创建
{
	int data;
	Stacknode* next;
}Stacknode, * LinkStackPrt;



struct LinkStack//抽象出来一个结构 用来记录栈顶和元素个数 
{
	LinkStackPrt top;    // 栈顶指针，指向栈顶元素  
	int count = 0;         // 栈中元素的数量  
};

bool InitStack(LinkStack* L);
void Push(LinkStack* L, int e);//压栈
bool Pop(LinkStack* L, int e);//弹栈
bool StackEmpty(LinkStack* L);//判断栈是否为空
void CreatStack(LinkStack* L, const int n);//创建栈
int Getcount(LinkStack* L);//获取栈的元素个数
bool DeleteStack(LinkStack* L);//清空栈


bool InitStack(LinkStack *L)
{

	L->top = nullptr;
	L->top->next = nullptr;
	return true;
}


void Push(LinkStack* L, int e)//压栈的具体操作
{
	LinkStackPrt p = new Stacknode;
	p->data = e;
	p->next = L->top;
	L->top = p;
	L->count++;
}


bool StackEmpty(LinkStack* L)//判断栈是否为空
{
	if (!L->top) return true;
	else return false;
}

bool Pop(LinkStack* L, int e)//弹栈
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

void CreatStack(LinkStack* L, const int n)//创建一个栈
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

bool DeleteStack(LinkStack* L)//清空栈
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