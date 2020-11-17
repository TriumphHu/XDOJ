#include<iostream>
#include<string>
#define MaxVertex 105
#define INF 100000   //自定义无穷大
typedef int Vertex;
using namespace std;
int G[MaxVertex][MaxVertex]; //图
int N; //动物数
int M; //边数
int dist[MaxVertex][MaxVertex]; //距离
void build(); //初始化
void Floyd();
int FindMax(Vertex s); //查找每个源点到其他点的最大值
void FindMin(); //查找每个源点到其他点的最大值中的最小值
int main()
{
	build();
	Floyd();
	FindMin();
	return 0;
}
void build() //初始化
{
	Vertex v1, v2;
	int w;
	cin >> N >> M;
	for (Vertex i = 1; i <= N; i++)
	{
		for (Vertex j = 1; j <= N ; j++)
		{
			G[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++)
	{
		cin >> v1 >> v2 >> w;
		G[v1][v2] = w;
		G[v2][v1] = w;


	}
}
void Floyd()
{
	//初始化dist数组，让每个dist距离为无穷大
	for (Vertex i = 1; i <= N; i++)
	{
		for (Vertex j = 1; j <= N; j++)
		{
			dist[i][j] = G[i][j];
		}
	}
	for (Vertex k = 1; k <= N; k++)  //Floyd算法
	{
		for (Vertex i = 1; i <= N ; i++)
		{
			for (Vertex j = 1; j <= N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}
int FindMax(Vertex s) //查找每个源点到其他点的最大值
{
	int max = 0;
	for (Vertex i = 1; i <= N ; i++)
	{
		if (s != i && max < dist[s][i])
			max = dist[s][i];
	}
	return max;
}
void FindMin() //查找每个源点到其他点的最大值中的最小值
{
	int ItemMax;
	int min = INF;
	int animal;
	for (Vertex i = 1; i <= N; i++)
	{
		ItemMax = FindMax(i);
		if (ItemMax == INF)
		{
			cout << 0 << endl;
			return;
		}
		if (ItemMax < min)
		{
			min = ItemMax;
			animal = i;
		}
	}
	cout << animal << " " << min << endl;
}
