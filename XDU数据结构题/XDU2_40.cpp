#include<iostream>
using namespace std;
typedef struct //�����Ԫ�����ṹ��
{
	int coef; //ϵ��
	int exp;  //ָ��
} PolyTerm;
typedef struct
{
	PolyTerm* data; //data��֮ǰ������
	int last;
} SqPoly;   //�ܵ�ʽ�ӣ�������ÿһ���ָ���Լ������յ�
bool PolyInit(SqPoly& L); //��ʼ������ʽ��������ʽ��ֵ
double PolySum(SqPoly& L, double x0); //�����ʽ�ĺ�
bool PolyMinus(SqPoly& L, SqPoly& L1, SqPoly& L2);//����������ʽ�Ĳ�
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
	cout << "������x��ȡֵ" << endl;
	cin >> x0;
	double res = PolySum(s, x0);
	cout << res;
	return 0;
}
bool PolyInit(SqPoly& L)
{
	int i;
	PolyTerm* p;
	cout << "���������ʽ����������";
	cin >> L.last;  //�����ж���λ
	L.data = (PolyTerm*)malloc(L.last * sizeof(PolyTerm));
	if (!L.data) //�������ռ䲻�ɹ��Ļ�
		return false;
	p = L.data;
	for (i = 0; i < L.last;i++)
	{
		cout << "������ϵ��  ";
		cin >> p->coef;
		cout << "������ָ��  ";
		cin >> p->exp;
		p++;
	}
	return true;

}
double PolySum(SqPoly& L, double x0)
{
	double Pn, x;//Pn�ǽ����x��δ֪��
	int i, j; //i�Ƕ���ʽ��������j�Ƕ���ʽ�Ĵ���
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
	int i = 0, j = 0, k = 0; //i��L1��������j��L2��������k���ܵ�����
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


