#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n,Max;
int Graphic[105][105] = {};  //图的邻接矩阵
int InDegree[105] = {};		 //入度
int OutDegree[105] = {};	 //出度
int EarlyTime[105] = {};     //最早完成时间
void init();                 //初始化
bool TopSort();				 //拓扑排序
int main()
{
	init();
	if (TopSort())
		cout << Max << endl;
	else
		cout << "NO" << endl;
	return 0;
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Graphic[i][j];
			if (Graphic[i][j] != 0)
			{
				OutDegree[i]++;
				InDegree[j]++;
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
			EarlyTime[i] = 0;
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
				EarlyTime[i] = max(EarlyTime[i], EarlyTime[v] + Graphic[v][i]);
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
		Max = 0;
		for (int i = 1; i <= n; i++)
		{
			Max = max(Max, EarlyTime[i]);
		}
		return true;
	}
}
