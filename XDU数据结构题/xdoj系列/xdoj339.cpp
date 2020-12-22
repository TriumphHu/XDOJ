#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	int ar[105] = {};
	cin >> n;
	int times = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 0; k < n - i - 1; k++)
		{
			if (ar[k] > ar[k + 1])
			{
				temp = ar[k + 1];
				ar[k + 1] = ar[k];
				ar[k] = temp;
				times++;
			}
		}
	}
	
	cout << times;
	return 0;
}