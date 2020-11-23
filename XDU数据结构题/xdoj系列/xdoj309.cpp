#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n, m,temp;
	int matrix1[50][50] = {};
	int matrix2[50][50] = {};
	int matrix3[50][50] = {};
	int ar1[100] = {};
	int ar2[100] = {};
	cin >> n >> m;
	int t = 0;
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			cin >> temp;
			if(temp != 0)
			{
				matrix1[i][k] = temp;
				t++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{			
			if (matrix1[i][k] == 1)
			{
				cin >> temp;
				matrix1[i][k] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			cin >> temp;
			if (temp != 0)
			{
				matrix2[i][k] = temp;
				t++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (matrix2[i][k] == 1)
			{
				cin >> temp;
				matrix2[i][k] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (matrix1[i][k] != 0 || matrix2[i][k] != 0)
			{
				matrix3[i][k] = matrix1[i][k] + matrix2[i][k];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (matrix3[i][k] != 0)
				cout << 1 << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (matrix3[i][k] != 0)
				cout << matrix3[i][k] << " ";
		}
	}
	return 0;
}