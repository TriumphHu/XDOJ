#include<iostream>
#include<string>
#define INFINITE 999999
using namespace std; 
/*
	����⣬����ͨ��Floyd�㷨�ó����е㵽����������·����Ȼ���ٸ��������ȡ���ļ����õ���ʱ��
*/
int Graphic[25][25] = {};
int M, N, K;
void init();
void Floyd();
int DelayTime();
int main()        
{
	init();
	Floyd();
	int res = DelayTime();
	cout << res;
	return 0;
}
void init()
{
	cin >> M >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			Graphic[i][k] = INFINITE;
		}
	}
	int v1, v2, weight;
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> weight;
		Graphic[v1][v2] = weight;
	}
}
void Floyd()
{
	for (int i = 1; i <= N; i++)
	{
		Graphic[i][i] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (Graphic[k][j] > Graphic[k][i] + Graphic[i][j])
				{
					Graphic[k][j] = Graphic[k][i] + Graphic[i][j];
				}
			}
		}
	}
}
int DelayTime()
{
	int max = 0;
	for (int i = 1; i <= N; i++)
	{
		if (Graphic[K][i] >= INFINITE)
			return -1;
		if (Graphic[K][i] > max)
			max = Graphic[K][i];
	}
	return max;
}
