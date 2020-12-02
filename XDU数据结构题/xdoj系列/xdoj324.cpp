#include<iostream>
#include<string>
#include<queue>
using namespace std;
int n;
int Graphic[105][105] = {};
int HasVisted[105] = {};
void init();
int Count = 0;
void BFS(int t); 
int main()
{
	init();
	for (int i = 1; i <= n; i++)
	{
		if (!HasVisted[i])
		{
			BFS(i);
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
void BFS(int t)
{
	HasVisted[t] = 1;
	queue<int> q;
	q.push(t);
	int temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		cout << temp << " ";
		for (int i = 1; i <= n; i++)
		{
			if (Graphic[temp][i])
			{
				if (!HasVisted[i])
				{
					q.push(i);
					HasVisted[i] = 1;
				}
			}
		}
	}
	Count++;
}
