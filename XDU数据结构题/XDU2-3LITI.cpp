#include<iostream>
#include<string>
#define MAXSIZE 100 //定义静态数组最大储存数
using namespace std;
typedef char ElemType[6];
typedef struct
{
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE]; //定义静态数组的数据和储存结构
int Malloc(SLinkList space);
void Free(SLinkList space, int k);
void InitList(SLinkList L);
int main()
{
	SLinkList s = { {"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",0} };
	int i;
	i = s[0].cur;
	while (i)
	{
		cout << s[i].data<<endl;
		i = s[i].cur; //轮换到下一个
	}

	return 0;
}
int Malloc(SLinkList space)   //若链表非空，则返回第一个结点，否则返回0
{
	int i = space[0].cur;
	if (i)
		space[0].cur = space[i].cur;

	return i;
}
void Free(SLinkList space, int k) //将下标为k的结点回收到备用链表
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
void InitList(SLinkList L)
{
	int i;
	L[MAXSIZE - 1].cur = 0; //最后一个单元为空链表的表头
	for (i = 0; i < MAXSIZE - 2; i++)
	{
		L[i].cur = i + 1;
	}
	L[MAXSIZE - 2].cur = 0;
}