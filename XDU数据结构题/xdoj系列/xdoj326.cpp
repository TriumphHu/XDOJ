#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int Graphic[55][55] = {};
int M, N, K,Max; //M是行数，N是结点数，K是起点
int InDegree[105] = {};		 //入度
int OutDegree[105] = {};	 //出度
int EarlyTime[105] = {};     //最早完成时间
bool TopSort();
void init();
int main()
{
	init();
	if (TopSort())
		cout << Max << endl;
	else
		cout << -1;
	return 0;
}
void init()
{
	cin >> M >> N >> K;
	int col, row, weight;
	for (int i = 0; i < M; i++)
	{
		cin >> col >> row >> weight;
		Graphic[col][row] = weight;
		OutDegree[col]++;
		InDegree[row]++;
	}
}
bool TopSort()
{
	int count = 0;
	queue<int> q;
	//首先让入度为0的结点进队
	/*for (int i = 1; i <= N; i++)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
			EarlyTime[i] = 0;
		}
	}*/
	q.push(K);
	EarlyTime[K] = 0;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		count++;
		for (int i = 1; i <= N; i++) //对出队的每一个邻接点进行访问
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
	if (count != N)
	{
		return false;
	}
	else
	{
		Max = 0;
		for (int i = 1; i <= N; i++)
		{
			Max = max(Max, EarlyTime[i]);
		}
		return true;
	}
}