#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n;
int Graphic[105][105] = {};
int HasVisted[105] = {};
void init();
int Count = 0;
void DFS(int t);
int main()
{
	init();
	for (int i = 1; i <= n; i++)
	{
		if (!HasVisted[i])
		{
			DFS(i);
			Count++;
		}
	}
	cout << endl << Count << endl;
	return 0;
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			cin >> Graphic[i][k];
		}
	}
}
void DFS(int t)
{
	HasVisted[t] = 1;
	cout << t << " ";
 	for (int i = 1; i <= n; i++)
	{
		if (Graphic[t][i])
		{
			if (!HasVisted[i])
			{
				DFS(i);
			}
		}
	}
}
