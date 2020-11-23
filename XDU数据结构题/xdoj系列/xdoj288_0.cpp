#include<iostream>
#include<string>
using namespace std;
//得到字符串的next数组
int* getNext(string s);
int main()
{
	int n;
	cin >> n;
	char ch;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> ch;
		s += ch;
	}
	int* next = getNext(s);
	for (int i = 0; i < n; i++)
	{
		cout << next[i] << " ";
	}
	return 0;
}
int* getNext(string s)
{
	int i = 0;
	int j = -1;
	int len = s.size();
	int* next = new int[len + 5]; //感谢谢铭松大佬，提醒这里给next开大一点！！！
	next[0] = -1;
	while(i < len)
	{
		if (j == -1 || s[i] == s[j]) //这里是字符串的i，j。而不是next的。
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}