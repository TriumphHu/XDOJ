#include<iostream>
#include<string>
using namespace std;
typedef struct PolyTerm* SqPoly; //多项式指针指向下一位
struct PolyTerm  //定义多项式
{
	int length; //项数
	int coef; //系数
	int exp; //指数
	SqPoly next;
};
SqPoly init(); //初始化分配空间(记得写返回值)
SqPoly SqInit(SqPoly sq); //初始化多项式并返回(记得写返回值) 设置了头结点
void PrintSq(SqPoly sq); //打印多项式
SqPoly AddSq(SqPoly s1, SqPoly s2); //多项式的求和，返回新的多项式
SqPoly SubSq(SqPoly s1, SqPoly s2); //多项式的求差，返回新的多项式

int main()
{
	SqPoly addsq, subsq, sq1, sq2;
	sq1 = init();
	sq2 = init();
	sq1 = SqInit(sq1);
	sq2 = SqInit(sq2);
	addsq = AddSq(sq1, sq2);
	PrintSq(addsq);
	subsq = SubSq(sq1, sq2);
	PrintSq(subsq);
	return 0;
}
SqPoly init()
{
	SqPoly sq = (SqPoly)malloc(sizeof(struct PolyTerm));
	sq->next = NULL;
	return sq;
}
SqPoly SqInit(SqPoly sq)
{
	SqPoly start = sq;
	SqPoly s = init();
	int len;
	cin >> len;
	s->length = len;
	for (int i = 0; i < len; i++)
	{
		cin >> s->coef;
		cin >> s->exp;
		sq->next = s;
		sq = s;
		s = init();
	}
	return start;
}
void PrintSq(SqPoly sq)
{
	if (sq == NULL)
	{
		cout << 0 << endl;
		return;
	}
	sq = sq->next;
	cout << sq->length << " ";
	while (sq)
	{
		cout << sq->coef << " " << sq->exp << " ";
		if (sq->next == NULL)
		{
			cout << endl;
			return;
		}
		sq = sq->next;
	}
	cout << endl;
}
SqPoly AddSq(SqPoly s1, SqPoly s2)
{
	int len = 0;
	SqPoly start1 = s1;
	SqPoly start2 = s2;
	s1 = s1->next;
	s2 = s2->next;
	SqPoly sq = (SqPoly)malloc(sizeof(struct PolyTerm));
	SqPoly start = sq;   //给最开始的位置记住
	SqPoly temp = init();
	while (s1 && s2)
	{
		if (s1->exp > s2->exp)
		{
			temp->exp = s1->exp;
			temp->coef = s1->coef;
			sq->next = temp;
			sq = temp;
			s1 = s1->next;
			len++;
		}
		else if (s1->exp < s2->exp)
		{
			temp->exp = s2->exp;
			temp->coef = s2->coef;
			sq->next = temp;
			sq = temp;
			s2 = s2->next;
			len++;
		}
		else
		{
			temp->coef = s1->coef + s2->coef;
			temp->exp = s1->exp;
			if (temp->coef == 0)
			{
				s1 = s1->next;
				s2 = s2->next;
				temp = init();
				continue;
			}
			sq->next = temp;
			sq = temp;
			s1 = s1->next;
			s2 = s2->next;
			len++;
		}
		temp = init();
	}
	while (s1)
	{
		temp->exp = s1->exp;
		temp->coef = s1->coef;
		sq->next = temp;
		sq = temp;
		s1 = s1->next;
		temp = init();
		len++;
	}
	while (s2)
	{
		temp->exp = s2->exp;
		temp->coef = s2->coef;
		sq->next = temp;
		sq = temp;
		s2 = s2->next;
		temp = init();
		len++;
	}
	s1 = start1;
	s2 = start2;
	if (len == 0)
		return NULL;
	start->next->length = len;
	return start;
}
SqPoly SubSq(SqPoly s1, SqPoly s2)
{
	int len = 0;
	SqPoly start1 = s1;
	SqPoly start2 = s2;

	s1 = s1->next;

	s2 = s2->next;
	SqPoly sq = (SqPoly)malloc(sizeof(struct PolyTerm)); //新的多项式，用于接收结果
	SqPoly start = sq;
	SqPoly temp = init();
	while (s1 && s2)
	{
		if (s1->exp > s2->exp)
		{
			temp->exp = s1->exp;
			temp->coef = s1->coef;
			sq->next = temp;
			sq = temp;
			s1 = s1->next;
			len++;
		}
		else if (s1->exp < s2->exp)
		{
			temp->exp = s2->exp;
			temp->coef = -s2->coef;
			sq->next = temp;
			sq = temp;
			s2 = s2->next;
			len++;
		}
		else
		{
			temp->coef = s1->coef - s2->coef;
			temp->exp = s1->exp;
			if (temp->coef == 0)
			{
				s1 = s1->next;
				s2 = s2->next;
				temp = init();
				continue;
			}
			sq->next = temp;
			sq = temp;
			s1 = s1->next;
			s2 = s2->next;
			len++;
		}
		temp = init();
	}
	while (s1)
	{
		temp->exp = s1->exp;
		temp->coef = s1->coef;
		sq->next = temp;
		sq = temp;
		s1 = s1->next;
		temp = init();
		len++;
	}
	while (s2)
	{
		temp->exp = s2->exp;
		temp->coef = -s2->coef;
		sq->next = temp;
		sq = temp;
		s2 = s2->next;
		temp = init();
		len++;
	}
	s1 = start1;
	s2 = start2;
	if (len == 0)
		return NULL;
	start->next->length = len;
	return start;
}
