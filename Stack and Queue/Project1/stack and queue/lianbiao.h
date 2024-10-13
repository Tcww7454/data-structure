#include<iostream>
using namespace std;


struct Lnode
{
	int data;//节点数据 
	Lnode* next;//指向下一个节点的指针 
};//节点的声明 
typedef Lnode* LinkList;//换一个名字 
bool InitList(LinkList& L);//头节点的初始化 
void CreatList(LinkList& L, int m_size);//创造单链表 
void GetList(LinkList& L, int m_size);//遍历链表 
void ChaList(LinkList& L, int i, int e);//插入一个元素
void deleteList(LinkList& L, int i);//删除 
LinkList AgainstList(LinkList& L);//返置链表
LinkList IntergreatList(LinkList& La, LinkList& Lb, LinkList& Lc);//合并链表




bool InitList(LinkList& L)//对Lnode类型的指针的引用 
{
	L = new Lnode;
	L->next = nullptr;
	return true;
}

void CreatList(LinkList& L, int m_size)//创建一个单链表
{
	for (int i = 0; i < m_size; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void GetList(LinkList& L, int m_size)//单链表的遍历 
{
	LinkList p;
	p = L; int j = 0;
	while (p && j < m_size)
	{
		p = p->next;
		++j;
	}
}

void ChaList(LinkList& L, int i, int e) //在第i个位置插入e 
{
	LinkList p;
	p = L->next; int j = 0;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	Lnode* s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void deleteList(LinkList& L, int i)//删除第i个节点 
{
	LinkList p;
	p = L->next; int j = 0;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	Lnode* q = p->next;
	p->next = p->next->next;
	delete q;
}


LinkList AgainstList(LinkList& L)//链表的转置
{
	LinkList p = L->next;
	L->next = NULL;
	LinkList r;
	while (p != NULL)
	{
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}




LinkList IntergreatList(LinkList& La, LinkList& Lb, LinkList& Lc)//两个有序链表的合并
{
	Lnode* pa = La->next;
	Lnode* pb = Lb->next;
	Lc = La;
	Lnode* pc = Lc;
	while (pa && pb)
	{
		if (pa->data >= pb->data)
		{
			pc->next = pb;
			pc = pc->next;
			pb = pb->next;
		}
		else
		{
			pc->next = pa;
			pc = pc->next;
			pa = pa->next;
		}
	}
	pc->next = (pa ? pa : pb);
	delete Lb;
	return Lc;
}