#include<iostream>
#include<string>
using namespace std;
typedef int elemType;
typedef struct LNode* List; //ע�⣬���struct©��
struct LNode
{
	elemType data;
	List next;
};
List init();
List insert(elemType x, int i, List L);
List findKth(int k, List L);
void printList(List L);
int length(List L);
List find(elemType x, List L);
List Delete(int i, List L);
int FindLocate(elemType x, List L);//����xԪ�����������е���ţ��������ڸ�Ԫ���򷵻�-1
List init()
{
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}
List insert(elemType x, int i, List L)
{
	List p, s;
	if (i == 1)
	{
		s = (List)malloc(sizeof(struct LNode));
		s->data = x;
		s->next = L;
		return s;
	}
	p = findKth(i - 1, L);
	if (!p)
	{
		cout << "�ڵ����" << endl;
		return NULL;
	}
	else
	{
		s = (List)malloc(sizeof(struct LNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return L;
	}

}
List findKth(int k, List L)
{
	List p = L;
	int i = 1;
	while (p && i < k)
	{
		p = p->next;
		i++;
	}
	if (i == k)
		return p;
	else
		return NULL;
}
void printList(List L)
{
	List t;
	int flag = 1;
	cout << "��ǰ����Ϊ��";
	for (t = L; t;t = t->next)
	{
		cout << t->data << "  ";
		flag = 0;
	}
	cout << endl;
	if (flag)
		cout << "null";
}
int length(List L)
{
	List P = L;
	int len = 0;
	while (P)
	{
		P = P->next;
		len++;
	}
	return len;
}
List find(elemType x, List L)
{
	List p = L;
	while (p && p->data != x)
	{
		p = p->next;
	}
	return p;
}
List Delete(int i, List L)
{
	List p, s;
	if (i == 1)  //���Ҫɾ��ͷ���
	{
		s = L;
		if (L) //ͷ��㲻Ϊ��
		{
			L = L->next;
		}
		else
		{
			return NULL;
		}
		free(s); //�ͷű�ɾ���Ľ��
		return L;
	}
	p = findKth(i - 1, L);
	if (!p || !(p->next))
	{
		cout << "�����󣡣�";
		return NULL;
	}
	s = p->next;
	p->next = s->next;
	free(s);
	return L;
}
int FindLocate(elemType x, List L)
{
	int locate = 1;
	List p = L;
	while (p && p->data <= x)
	{
		if (p->data == x)
		{
			return locate;
		}
		locate++;
		p = p->next;
	}
	return -1;
}