#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	//��û���ù鲢����ķ���
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