#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	//并没有用归并排序的方法
	int ar[205] = {};
	int n, m, t;
	cin >> n >> m;
	t = n + m;
	for (int i = 0; i < t; i++)
		cin >> ar[i];
	sort(ar, ar + t);
	for (int i = 0; i < t; i++)
		cout << ar[i] << " ";
	return 0;
}