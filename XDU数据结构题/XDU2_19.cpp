#include<iostream>
#include "Link.h"
using namespace std;
List DeleteRange(int mink,int maxk,List L); //ɾ��ֵ��mink��maxk֮���Ԫ�أ�����������
int main()
{
	List L;
	L = init();
	L = insert(999, 1, L);
	L = insert(888, 1, L);
	L = insert(777, 1, L);
	L = insert(66, 1, L);
	L = insert(65, 1, L);
	L = insert(64, 1, L);
	L = insert(6, 1, L);
	L = insert(5, 1, L);
	L = insert(3, 1, L);
	L = insert(0, 1, L);
	printList(L);
	cout << "����������һ��DeleteRange����������������ɾ���ķ�Χ" << endl;
	int mink, maxk;
	cin >> mink >> maxk;
	L = DeleteRange(mink, maxk, L);
	printList(L);
	
	return 0;
}
List DeleteRange(int mink, int maxk, List L)
{
	List pre,temp,p = L;
	pre = p;
	int flag = 0;
	if (mink >= maxk)
	{
		cout << "����ʲô��Χ����С�����ԣ�";
		return NULL;
	}
	while (p && p->data < maxk)
	{
		if (p->data <= mink)
		{
			pre = p;
			p = p->next;
		}
		else
		{
			pre->next = p->next;
			temp = p;
			p = p->next;
			free(temp);
		}
	}
	return L;
}
