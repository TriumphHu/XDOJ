#include<iostream>
#include<string>
using namespace std;
//�õ��ַ�����next����
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
	int* next = new int[len + 5]; //��лл���ɴ��У����������next����һ�㣡����
	next[0] = -1;
	while(i < len)
	{
		if (j == -1 || s[i] == s[j]) //�������ַ�����i��j��������next�ġ�
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