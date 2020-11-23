#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	int n,temp,num;
	num = 1;
	cin >> n;
	stack<int> s;
	int ar[15];
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	s.push(num);
	num++;
	for (int i = 0; i < n; i++)
	{
		temp = ar[i];
		while(s.empty() || s.top() < temp)
		{
			s.push(num);
			num++;
		}
		if (temp == s.top())
		{
			s.pop();
		}
	}
	if (s.empty())
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}