#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	stack<char> s;
	int n;
	char c,temp;
	cin >> n;
	if (n % 2 == 1) //������������򲻿����м��Ǹ��ַ�
	{
		for (int i = 0; i < n / 2; i++) //�������ַ�����ջ��
		{
			cin >> c;
			s.push(c);
		}
		cin >> temp;
		for (int i = n / 2 + 1; i < n; i++)
		{
			cin >> c;
			if (c == s.top())
			{
				s.pop();
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
		return 0;
	}
	if (n % 2 == 0) 
	{
		for (int i = 0; i < n / 2; i++) //�������ַ�����ջ��
		{
			cin >> c;
			s.push(c);
		}
		for (int i = n / 2 ; i < n; i++)
		{
			cin >> c;
			if (c == s.top())
			{
				s.pop();
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
		cout << "YES";
		return 0;
	}
	return 0;
}