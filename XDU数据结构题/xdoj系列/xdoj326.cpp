#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int Graphic[55][55] = {};
int M, N, K,Max; //M��������N�ǽ������K�����
int InDegree[105] = {};		 //���
int OutDegree[105] = {};	 //����
int EarlyTime[105] = {};     //�������ʱ��
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
	//���������Ϊ0�Ľ�����
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
		for (int i = 1; i <= N; i++) //�Գ��ӵ�ÿһ���ڽӵ���з���
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