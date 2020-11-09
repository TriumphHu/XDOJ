#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int len = s.size();
	int cycle = 1,i = 0;
	for (;cycle <= len; cycle++)
	{
		while (s[i] == s[i + cycle])
		{
			i++;
			if (i + cycle == len - 1)
			{
				cout << cycle;
				return 0;
			}
		}
		
		i = 0;
	}
	cout << cycle-1;
	return 0;
}