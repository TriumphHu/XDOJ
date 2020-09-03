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
List makeEmpty();//��ʼ������
int length(List L);//�Ա�������ķ�ʽ�����鳤��
List insert(int num, int n, List L);//��num��������L��nλ��
void printList(List L);//�������Ԫ��
List FindKth(int i, List L);//���ҵ�i��Ԫ��
int main()
{
	cout << " List makeEmpty();//��ʼ������ " << endl;
	cout << " int length(List L);//�Ա�������ķ�ʽ�����鳤�� " << endl;
	cout << " List insert(int num, int n, List L);//��num��������L��nλ�� " << endl;
	cout << " void printList(List L); //�������Ԫ��" << endl;
	cout << "�ȴ���һ������,�ٲ�������Ԫ��" << endl;
	cout << "List FindKth(int i, List L);//���ҵ�i��Ԫ��" << endl;
	L = makeEmpty();
	printList(L);
	L = insert(1, 0, L);
	printList(L);
	L = insert(2, 1, L);
	printList(L);
	L = insert(3, 1, L);
	printList(L);
	return 0;
}
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
	return n;
}
List insert(int num, int n, List L)
{
	int times = 0;
	List temp,t;
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