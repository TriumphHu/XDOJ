#include<iostream>
#include<string>
#include "LINK.h"
using namespace std;
List La, Lb;
void init(); ////初始化两个链表



int main()
{
	init();//创造两个链表
	printList(La);
	printList(Lb);
	List Lc = makeEmpty();
	int len_a = length(La);
	int len_b = length(Lb);
	int temp;
	
	for (int i = 0,n = 0; i < len_b; i++)
	{	
		temp = FindKth(i , Lb)->Data;
		if (FindLocate(temp,La) != -1)
		{
			insert(temp, n, Lc);
			n++;
		}
	}
	printList(Lc);
	return 0;
}

void init()
{
	La = makeEmpty();
	Lb = makeEmpty();
	insert(1, 0, La);
	insert(2, 0, La);
	insert(3, 0, La);
	insert(666, 0, La);
	insert(777, 3, La);
	insert(888, 0, La);
	insert(4, 0, La);
	insert(6, 0, Lb);
	insert(3, 0, Lb);
	insert(2, 0, Lb);
	insert(1, 0, Lb);
	insert(888, 0, Lb);
	insert(777, 0, Lb);
	insert(65, 0, Lb);
	insert(14, 3, Lb);


}