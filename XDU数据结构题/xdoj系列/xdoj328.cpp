#include<iostream>
#include<string>
using namespace std;
int hKey(int n);
int m, p;
int ar[105] = {};
int lingerResearch(int n, int key);
int key;
int times = 0;
int ifHave(int key);
int main()
{
	cin >> m >> p;
	int temp,poc,have;
	int flag = 1;
	for (int i = 0; i < 105; i++)
	{
		ar[i] = -1;
	}
	cin >> temp;
	while (temp != -1)
	{
		have = ifHave(temp);
		if (have == -1)
		{
			key = hKey(temp);
			if (ar[key] == -1)
			{
				ar[key] = temp;
				times++;
				cout << key << endl;
			}
			else
			{
				flag = lingerResearch(key, temp);
			}
			if (flag == 0)
				break;
		}
		else
		{
			cout << have << endl;
		}
		cin >> temp;
	}
	

	return 0;
}
int hKey(int n)
{
	int key;
	key = n % p;
	return key;
}
int lingerResearch(int n, int key)
{
	int pocTemp = n;
	int d = 1;
	while (times != (m - 1) && ar[pocTemp] != -1 )
	{
		pocTemp = (n + d) % m;
		d++;
	}
	if (times == m - 1)
	{
		cout << "Table full" << endl;
		return 0;
	}
	else
	{
		cout << pocTemp << endl;
		ar[pocTemp] = key;
		times++;
	}
		
	return 1;
}
int ifHave(int key)
{
	for (int i = 0; i < 105; i++)
	{
		if (ar[i] == key)
			return i;
	}
	return -1;

}