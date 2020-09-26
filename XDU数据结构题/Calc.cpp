#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> cal; //���ڴ����������ջ
char str[20];  //����ת������׺���ʽ
void Calc(string s); //����׺���ʽת��Ϊ��׺���ʽ
int getValue(char s);//�����������ȼ�
void Result(string s); //�����׺���ʽ��ֻ�����ڸ�λ���ֵ�+-*/����
double CToD(char ch);//��char�ַ�ת���double����
int main()
{
	string s = "1+2-3*4+5/6-7+8*9";
	Calc(s);
	cout << endl;
	cout <<  " str is "<<str <<endl;
	Result(str);
	
	return 0;
}
void Calc(string s)
{
	int t = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			cout << s[i] << " ";
			str[t] = s[i];
			t++;
		}
		else
		{
			if (cal.empty())
			{
				cal.push(s[i]);
			}
			else if(getValue(s[i]) <= getValue(cal.top())) //����һλ��������ȼ�����ǰһλ����ǰһλ�����ȡ��
			{
				cout << cal.top() << " ";
				str[t] = cal.top();
				t++;
				cal.pop();
				while (!cal.empty() && getValue(cal.top()) == getValue(s[i]))
				{
					cout << cal.top() << " ";
					str[t] = cal.top();
					t++;
					cal.pop();
				}
				cal.push(s[i]);
			}
			else
			{
				cal.push(s[i]);
			}
		}
	}
	while (cal.size())
	{
		cout << cal.top() << " ";
		str[t] = cal.top();
		t++;
		cal.pop();
	}
}
int getValue(char s)
{
	if (s == '+' || s == '-')
	{
		return 1;
	}
	else if(s == '*' || s == '/')
	{
		return 2;
	}
}
void Result(string s) //�����׺���ʽ
{
	double res;
	double temp1,temp2;
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
			else if(s[i] == '-')
			{
				res = temp1 - temp2;
			}
			else if(s[i] == '*')
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
	cout << "����Ľ����" <<number.top();
}
double CToD(char ch)
{
	int temp;
	temp = ch - '0';
	return (double)temp;
}