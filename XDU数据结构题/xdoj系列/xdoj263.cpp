#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n, m;
	int t = 0;
	cin >> n >> m;
	int ar[1000] = {};
	ar[0] = m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}
	sort(ar, ar + n + 1);
	for ( t= 0; t < n; t++)
	{
		cout << ar[t] <<" ";
	}
	cout << ar[t];
	return 0;
}