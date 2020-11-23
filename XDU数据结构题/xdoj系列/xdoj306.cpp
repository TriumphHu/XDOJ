#include<iostream>
#include<string>
#include<stack>
using namespace std;
void Result(string s); //�����׺���ʽ��ֻ�����ڸ�λ���ֵ�+-*/����
double CToD(char ch);//��char�ַ�ת���double����
int main()
{
	string s;
	cin >> s;
	Result(s);
	return 0;
}
void Result(string s) //�����׺���ʽ
{
	double res;
	double temp1, temp2;
	stack<double> number;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number.push(CToD(s[i])); //���ַ�ת����double���ʹ���ջ��
		}
		else
		{
			temp2 = number.top();
			number.pop();
			temp1 = number.top();
			number.pop();
			if (s[i] == '+')
			{
				res = temp1 + temp2;
			}
			else if (s[i] == '-')
			{
				res = temp1 - temp2;
			}
			else if (s[i] == '*')
			{
				res = temp1 * temp2;
			}
			else
			{
				res = temp1 / temp2;
			}
			number.push(res);
		}
	}
	cout << number.top();
}
double CToD(char ch)
{
	int temp;
	temp = ch - '0';
	return (double)temp;
}