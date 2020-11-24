#include<iostream>
#include<string>
using namespace std;
int ar[105] = {};

int main()
{
	int n, key, before, mid, behind, temp;
	cin >> n >> key;
	before = 0;
	behind = n - 1;
	mid = (behind - before) / 2;
	for (int i = 0; i < n; i++)
	{
		cin >> ar[i];
	}
	temp = ar[mid];
	while (temp != key && behind - before != 1 && behind - before != 0)
	{
		
		cout << temp << " ";
		if (temp < key)
		{
			before = mid+1;
			mid = (behind + before) / 2;
		}
		else
		{
			behind = mid-1;
			mid = (behind + before) / 2;
		}
		temp = ar[mid];
	}
	cout << temp<< endl;
	if (temp == key)
		cout << "Eureka!" << endl;
	else
		cout << "Search failed!" << endl;
	return 0;
}