#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a[101], b[101];
	int n;
	int k = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			b[k] = a[i];
			k++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			b[k] = a[i];
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}