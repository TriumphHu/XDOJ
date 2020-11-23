#include<iostream>
#include<string>
using namespace std;
int main()
{
	int m, n; //mÐÐnÁÐ
	cin >> m >> n;
	int a[30][30];
	int row[30] = {};
	int col[30];
	int num[30];
	int tool = 0;
	int flag = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	int rowMin, colMax,tempx,tempy;
	for (int i = 1; i <= m; i++)
	{
		rowMin = a[i][1];
		for (int j = 1; j <= n; j++)
		{
			if (rowMin >= a[i][j])
			{
				rowMin = a[i][j];
				tempx = i;
				tempy = j;
			}
		}
		for (int k = 1; k <= m; k++)
		{
			if (a[k][tempy] > rowMin)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			row[tool] = tempx;
			col[tool] = tempy;
			num[tool] = rowMin;
			tool++;
		}
		flag = 1;
	}
	//cout << "row[0] is " << row[0] << endl;
	if (row[0] == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < tool; i++)
	{
		cout << row[i] << " " << col[i] << " " << num[i] << endl;
	}
	return 0;
}