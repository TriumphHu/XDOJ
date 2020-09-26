#include<iostream>
#include<string>
#include<stack>
using namespace std;

stack<char> cal; //用于储存运算符的栈
char str[20];  //储存转换完后后缀表达式
void Calc(string s); //将中缀表达式转换为后缀表达式
int getValue(char s);//获得运算符优先级
void Result(string s); //计算后缀表达式，只能用于个位数字的+-*/计算
double CToD(char ch);//将char字符转变成double类型
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
			else if(getValue(s[i]) <= getValue(cal.top())) //若后一位运算符优先级低于前一位，将前一位运算符取出
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
void Result(string s) //计算后缀表达式
{
	double res;
	double temp1,temp2;
	stack<double> number;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			number.push(CToD(s[i])); //将字符转换成double类型存入栈中
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
	cout << "运算的结果是" <<number.top();
}
double CToD(char ch)
{
	int temp;
	temp = ch - '0';
	return (double)temp;
}