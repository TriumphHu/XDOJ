
#include <iostream>
#include <string>
using namespace std;
int main() //��������к�
{
	int n;
	int a[500];
	cout << "���������и���" << endl;
	cin >> n;
	cout << "����������" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int thisSum , maxSum;
	thisSum = maxSum = 0;
	for (int i = 0; i < n; i++)
	{
		thisSum += a[i];
		if (thisSum > maxSum)
			maxSum = thisSum;
		else if(thisSum < 0)	
		{
			thisSum = 0;
		}
	}
	cout << "maxSum is "<< maxSum;
	return 0;
}