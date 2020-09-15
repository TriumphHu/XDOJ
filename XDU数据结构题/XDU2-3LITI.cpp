#include<iostream>
#include<string>
#define MAXSIZE 100 //���徲̬������󴢴���
using namespace std;
typedef char ElemType[6];
typedef struct
{
	ElemType data;
	int cur;
}component,SLinkList[MAXSIZE]; //���徲̬��������ݺʹ���ṹ
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
		i = s[i].cur; //�ֻ�����һ��
	}

	return 0;
}
int Malloc(SLinkList space)   //������ǿգ��򷵻ص�һ����㣬���򷵻�0
{
	int i = space[0].cur;
	if (i)
		space[0].cur = space[i].cur;

	return i;
}
void Free(SLinkList space, int k) //���±�Ϊk�Ľ����յ���������
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
void InitList(SLinkList L)
{
	int i;
	L[MAXSIZE - 1].cur = 0; //���һ����ԪΪ������ı�ͷ
	for (i = 0; i < MAXSIZE - 2; i++)
	{
		L[i].cur = i + 1;
	}
	L[MAXSIZE - 2].cur = 0;
}