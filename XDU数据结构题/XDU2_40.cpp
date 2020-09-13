#include<iostream>
using namespace std;
typedef struct //定义多元函数结构体
{
	int coef; //系数
	int exp;  //指数
} PolyTerm;
typedef struct
{
	PolyTerm* data; //data即之前的数据
	int last;
} SqPoly;   //总的式子，储存着每一项的指针以及最后的终点
bool PolyInit(SqPoly& L); //初始化多项式，给多项式赋值
double PolySum(SqPoly& L, double x0); //求多项式的和
bool PolyMinus(SqPoly& L, SqPoly& L1, SqPoly& L2);//求两个多项式的差
int main()
{
	double x0;
	SqPoly s ;
	s.data = (PolyTerm*)malloc(10 * sizeof(PolyTerm));
	s.last = 10;
	SqPoly s1;
	SqPoly s2;
	PolyInit(s1);
	PolyInit(s2);
	PolyMinus(s, s1, s2);
	cout << "请输入x的取值" << endl;
	cin >> x0;
	double res = PolySum(s, x0);
	cout << res;
	return 0;
}
bool PolyInit(SqPoly& L)
{
	int i;
	PolyTerm* p;
	cout << "请输入多项式的项数数：";
	cin >> L.last;  //就是有多少位
	L.data = (PolyTerm*)malloc(L.last * sizeof(PolyTerm));
	if (!L.data) //如果分配空间不成功的话
		return false;
	p = L.data;
	for (i = 0; i < L.last;i++)
	{
		cout << "请输入系数  ";
		cin >> p->coef;
		cout << "请输入指数  ";
		cin >> p->exp;
		p++;
	}
	return true;

}
double PolySum(SqPoly& L, double x0)
{
	double Pn, x;//Pn是结果，x是未知数
	int i, j; //i是多项式的项数，j是多项式的次数
	PolyTerm* p;
	p = L.data;
	for (i = 0, Pn = 0; i < L.last;i++, p++)
	{
		for (j = 0, x = 1;j < p->exp;j++)
		{
			x = x * x0;
		}
		Pn = Pn + p->coef * x;
	}
	return Pn;
}
bool PolyMinus(SqPoly& L, SqPoly& L1, SqPoly& L2)
{
	PolyTerm* p, * p1, * p2;
	p = L.data;
	p1 = L1.data;
	p2 = L2.data;
	int i = 0, j = 0, k = 0; //i是L1的项数，j是L2的项数，k是总的项数
	while (i < L1.last && j < L2.last)
	{
		if (p1->exp < p2->exp)
		{
			p->coef = p1->coef;
			p->exp = p1->exp;
			p++;k++;
			p1++;i++;
		}
		else
		{
			if (p1->exp > p2->exp)
			{
				p->coef = -p2->coef;
				p->exp = p2->exp;
				p++;k++;
				p2++;j++;
			}
			else
			{
				if (p1->coef != p2->coef)
				{
					p->coef = p1->coef - p2->coef;
					p->exp = p1->exp;
					p++;k++;
				}
				p1++;p2++;
				i++;j++;
			}
		}
	}
	if (i < L1.last)
	{
		while (i < L1.last)
		{
			p->coef = p1->coef;
			p->exp = p1->exp;
			p++;k++;
			p1++;i++;
		}
	}
	if (j < L2.last)
	{
		while (j < L2.last)
		{
			p->coef = p2->coef;
			p->exp = p2->exp;
			p++;k++;
			p2++;j++;
		}
	}
	L.last = k;
	return true;
}


