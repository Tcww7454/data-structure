#include<iostream>
using namespace std;


struct Lnode
{
	int data;//�ڵ����� 
	Lnode* next;//ָ����һ���ڵ��ָ�� 
};//�ڵ������ 
typedef Lnode* LinkList;//��һ������ 
bool InitList(LinkList& L);//ͷ�ڵ�ĳ�ʼ�� 
void CreatList(LinkList& L, int m_size);//���쵥���� 
void GetList(LinkList& L, int m_size);//�������� 
void ChaList(LinkList& L, int i, int e);//����һ��Ԫ��
void deleteList(LinkList& L, int i);//ɾ�� 
LinkList AgainstList(LinkList& L);//��������
LinkList IntergreatList(LinkList& La, LinkList& Lb, LinkList& Lc);//�ϲ�����




bool InitList(LinkList& L)//��Lnode���͵�ָ������� 
{
	L = new Lnode;
	L->next = nullptr;
	return true;
}

void CreatList(LinkList& L, int m_size)//����һ��������
{
	for (int i = 0; i < m_size; i++)
	{
		Lnode* p = new Lnode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void GetList(LinkList& L, int m_size)//������ı��� 
{
	LinkList p;
	p = L; int j = 0;
	while (p && j < m_size)
	{
		p = p->next;
		++j;
	}
}

void ChaList(LinkList& L, int i, int e) //�ڵ�i��λ�ò���e 
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

void deleteList(LinkList& L, int i)//ɾ����i���ڵ� 
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


LinkList AgainstList(LinkList& L)//�����ת��
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




LinkList IntergreatList(LinkList& La, LinkList& Lb, LinkList& Lc)//������������ĺϲ�
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