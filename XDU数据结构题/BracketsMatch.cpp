#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool brackMatch(char brack[],int len); //���鴫������������Ƿ�ƥ�䣬����ƥ�䷵��true 1�����򷵻�false 0��
int main()
{
	char brack[] = { '{','}','<','>','(','[',']',')',']','[','[',']',']','(','[','{','}',']',')'};
	int len = sizeof(brack) / sizeof(brack[0]);
	bool flag;
	flag = brackMatch(brack,len);
	cout <<"flag is  " <<flag <<endl;
	return 0;
}
bool brackMatch(char brack[],int len)
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
		cout << "true ";
		return true;
	}
	cout << "false , ��ǰδ��ƥ�䵽�������� ";
	cout << stk.size() << " �� "<<endl;
	return false;
}