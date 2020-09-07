#include <iostream>
#include <string>
using namespace std;
typedef struct LNode* List;
struct LNode
{
	int Data;
	List Next;
};
List L;
List makeEmpty();//初始化链表
int length(List L);//以遍历数组的方式求数组长度
List insert(int num, int n, List L);//将num插入链表L的n位置
void printList(List L);//输出链表元素
List FindKth(int i, List L);//查找第i个元素,第一个元素从1开始
int FindLocate(int num, List L);//查找num所存在的位置，若不存在则返回-1

List makeEmpty()
{
	List L = (List)malloc(sizeof(struct LNode));
	L->Data = 0;
	L->Next = 0;
	return L;
}
int length(List L)
{
	int n = 0;
	while (L)
	{
		n++;
		L = L->Next;

	}
	return n-1;
}
List insert(int num, int n, List L)
{
	int times = 0;
	List temp, t;
	t = FindKth(n, L);
	temp = (List)malloc(sizeof(struct LNode));
	temp->Data = num;
	temp->Next = t->Next;
	t->Next = temp;
	if (n == 0)
		return t;
	else
	{
		return L;
	}

}
void printList(List L)
{
	cout << "shuchu" << endl;
	L = L->Next;
	while (L)
	{
		cout << L->Data << endl;
		L = L->Next;
	}
}
List FindKth(int i, List L)
{
	List P = L;
	int n = 0;
	while (n != i)
	{
		P = P->Next;
		n++;
	}
	return P;
}
int FindLocate(int num, List L)
{
	int locate = 0;
	L = L->Next;
	while (L)
	{
		if (L->Data == num)
		{
			return locate;
		}
		
		locate++;
		L = L->Next;
	}
	return -1;

}