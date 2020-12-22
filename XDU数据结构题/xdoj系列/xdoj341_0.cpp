#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	int ar[105] = {};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	//≤Â»Î≈≈–Ú
	int temp,k;
	for (int i = 1; i < 4; i++)
	{
		temp = ar[i];
		for (k = i; k > 0 && ar[k - 1] > temp; k--)
		{
			ar[k] = ar[k - 1];
		}
		ar[k] = temp;
		for (int p = 0; p < n; p++)
		{
			cout << ar[p] << " ";
		}
		cout << endl;
	}
	return 0;
}