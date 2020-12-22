#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	
	int n;
	int ar[105] = {};
	int temp[40] = {};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	int t = n / 2;
	int times = 0;
	while (t > 0)
	{
		for (int i = 0; i < t; i++)
		{
			for (int k = i; k < n;)
			{
				temp[times] = ar[k];
				k += t;
				times++;
			}
			sort(temp, temp + times);
			times = 0;
			for (int k = i; k < n; )
			{
				ar[k] = temp[times];
				k += t;
				times++;
			}
			memset(temp, 0, 40 * sizeof(temp[0]));
			times = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cout << ar[i] << " ";
		}
		cout << endl;
		t = t / 2;
	}
	
	return 0;
}