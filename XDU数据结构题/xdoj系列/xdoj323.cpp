#include<iostream>
#include<string>
#include<queue>
using namespace std;
int InDegree[105] = {};		 //入度
int OutDegree[105] = {};	 //出度
int n; //结点数
int Graphic[105][105] = {};
bool TopSort();
void init();
void clear();
int main()
{
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		init();
		if (TopSort())
			cout << 0;
		else
			cout << 1;
		clear();

	}
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
			if (Graphic[i][k] != 0)
			{
				OutDegree[i]++;
				InDegree[k]++;
			}
		}
	}
}

bool TopSort()
{
	int count = 0;
	queue<int> q;
	//首先让入度为0的结点进队
	for (int i = 1; i <= n; i++)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
			
		}
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		count++;
		for (int i = 1; i <= n; i++) //对出队的每一个邻接点进行访问
		{
			if (Graphic[v][i] != 0)
			{
				
				InDegree[i]--;
				if (InDegree[i] == 0)
				{
					q.push(i);
				}
			}
		}
	}
	if (count != n)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void clear()
{
	memset(Graphic, 0, 105 * 105 * sizeof(Graphic[0][0]));
	memset(InDegree, 0, 105 * sizeof(InDegree[0]));
	memset(OutDegree, 0, 105 * sizeof(OutDegree[0]));
}