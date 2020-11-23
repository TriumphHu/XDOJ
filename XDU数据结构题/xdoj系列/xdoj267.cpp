#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
int main()
{
	int m,n,times, tempKey,keyi,tempNum;
	keyi = 0;
	
	int key[1005] = {};
	cin >>m>> n>>times;
	stack<int> s;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> key[i];
	}
	for (int ii = 0; ii < times; ii++)
	{
		int Numi = 0;
		int Num[1005] = {};
		for (int i = 0; i < n; i++) //Num[]为待测试的数组
			cin >> Num[i];
		tempKey = key[keyi];
		s.push(tempKey);
		keyi++;
		for (;keyi < n; ) //这里出问题了Numi不对
		{
			while (s.empty() || s.top() != Num[Numi])
			{
				s.push(key[keyi]);
				keyi++;
			}
			if (s.size() > m)
				break;
			while (!s.empty() && s.top() == Num[Numi])
			{
				s.pop();
				Numi++;
			}
		}
		if (s.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		while (!s.empty())
		{
			s.pop();
		}
		keyi = 0;
	}
	
	return 0;
}