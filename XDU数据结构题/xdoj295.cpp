#include<iostream>
#include<string>
using namespace std;
int a[101];
int b[101];
int c[202];
int main()
{
	int m, n,t;
	int up = 0, down = 0;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (t = 0; t < m + n; t++)
	{
		if (up == m || down == n)
		{
			if (up == m)
			{
				while (down != n)
				{
					c[t] = b[down];
					t++;
					down++;
				}
			}
			else
			{
				while (up != m)
				{
					c[t] = a[up];
					t++;
					up++;
				}
			}
			break;
		}
		else
		{
			if (a[up] < b[down])
			{
				c[t] = a[up];
				up++;
			}
			else if (a[up] > b[down])
			{
				c[t] = b[down];
				down++;
			}
			else
			{
				c[t] = a[up];
				up++;
				down++;
			}
		}
		
	}
	for (int i = 0; i < t; i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}