#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool brackMatch(char brack[], int len); //检验传入的括号数组是否匹配，若能匹配返回true 1；否则返回false 0；
int main()
{
	int n = 0;
	char s[10000] = {};
	char brack[1000] = {};
	char ch;
	int i = 0;
	cin.getline(s, 10000);
	while (s[i])
	{
		ch = s[i];
		if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
		{
			brack[n] = (char)ch;
			n++;
		}
		i++;
	}
	bool flag;
	flag = brackMatch(brack, n);
	if (flag)
		cout << "right" << endl;
	else
		cout << "wrong" << endl;
	return 0;
}
bool brackMatch(char brack[], int len)
{
	stack<char> stk;
	for (int i = 0; i < len; i++)
	{
		int flag = 0;
		switch (brack[i])
		{
		case '}':
			if (!stk.empty() && stk.top() == '{')
			{
				stk.pop();
				break;
			}
		case '>':
			if (!stk.empty() && stk.top() == '<')
			{
				stk.pop();
				break;
			}
		case ']':
			if (!stk.empty() && stk.top() == '[')
			{
				stk.pop();
				break;
			}
		case ')':
			if (!stk.empty() && stk.top() == '(')
			{
				stk.pop();
				break;
			}
		default:
			stk.push(brack[i]);
		}
	}
	if (stk.size() == 0)
	{
		return true;
	}
	return false;
}