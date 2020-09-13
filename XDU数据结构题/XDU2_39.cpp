#include<iostream>
using namespace std;
typedef struct //�����Ԫ�����ṹ��
{
	int coef; //ϵ��
	int exp;  //ָ��
} PolyTerm;
typedef struct
{
	PolyTerm* data;
	int last;
} SqPoly;   //�ܵ�ʽ�ӣ�������ÿһ���ָ���Լ������յ�
bool PolyInit(SqPoly& L); //��ʼ������ʽ��������ʽ��ֵ
double PolySum(SqPoly& L, double x0); //�����ʽ�ĺ�
int main()
{
	double x0;
	SqPoly s;
	PolyInit(s);
	cout << "������x��ȡֵ" << endl;
	cin >> x0;
	double res = PolySum(s,x0);
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