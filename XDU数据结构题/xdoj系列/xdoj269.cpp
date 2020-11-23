#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	int i = 1;
	int flag = 1;
	stack<char> stk;
	int len = s.size();
	int mid = len / 2;
	stk.push(s[0]);
	while (s[i])
	{
		if (len % 2 == 1)
		{
			if (i == mid)
				i++;
		}
		while (!stk.empty() && stk.top() == s[i])
		{
			
			stk.pop();
			i++;
			flag = 0;
			if (len % 2 == 1)
			{
				if (i == mid)
					i++;
			}
		}
		if (flag)
		{
			stk.push(s[i]);
			i++;
			if (len % 2 == 1)
			{
				if (i == mid)
					i++;
			}
		}
		flag = 1;
		
	}
	if (stk.empty())
		cout << "right" << endl;
	else
		cout << "wrong" << endl;
	return 0;
}