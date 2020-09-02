
#include <iostream>
#include <string>
using namespace std;
int main() //求最大子列和
{
	int n;
	int a[500];
	cout << "请输入序列个数" << endl;
	cin >> n;
	cout << "请输入序列" << endl;
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