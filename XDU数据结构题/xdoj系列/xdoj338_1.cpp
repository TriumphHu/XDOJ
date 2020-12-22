#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int ar[105] = {};
	for (int i = 0; i < n; i++)
		cin >> ar[i];
	int left, right;
	left = 0;
	right = n - 1;
	int prvotKey = ar[0];
	while (left != right)
	{
		while (ar[right] >= prvotKey && left != right)
		{
			right--;
		}
		if(left != right)
			swap(ar[left], ar[right]);
		while (ar[left] <= prvotKey && left != right)
		{
			left++;
		}
		if(left != right)
			swap(ar[left], ar[right]);
	}
	for (int i = 0; i < n; i++)
		cout << ar[i] << " ";
	return 0;
}