#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int ar[105] = {};
void heapSort(int parent);
int n;
int main()
{
	for (int i = 0; i < 105; i++)
	{
		ar[i] = -777;
	}
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> ar[i];
	}
	int parent = n / 2;
	while (parent >= 1)
	{
		heapSort(parent);
		parent--;
	}
	for (int i = 1; i <= n; i++)
		cout << ar[i] << " ";
	return 0;
}
void heapSort(int parent)
{
	int child = parent * 2;
	if (child <= n)
	{
		if (ar[child + 1] == -777)
		{
			if (ar[child] < ar[parent])
			{
				swap(ar[child], ar[parent]);
			}
		}
		else
		{
			int loc;
			if (ar[child] < ar[child + 1])
			{
				loc = child;
			}
			else
			{
				loc = child + 1;
			}
			if (ar[parent] > ar[loc])
			{
				swap(ar[parent], ar[loc]);
				if (ar[loc] > min(ar[loc * 2], ar[loc * 2 + 1]))
				{
					heapSort(loc);
				}
			}
		}
	}

}
