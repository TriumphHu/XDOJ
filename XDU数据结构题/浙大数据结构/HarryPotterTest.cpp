#include<iostream>
#include<string>
#define MaxVertex 105
#define INF 100000   //�Զ��������
typedef int Vertex;
using namespace std;
int G[MaxVertex][MaxVertex]; //ͼ
int N; //������
int M; //����
int dist[MaxVertex][MaxVertex]; //����
void build(); //��ʼ��
void Floyd();
int FindMax(Vertex s); //����ÿ��Դ�㵽����������ֵ
void FindMin(); //����ÿ��Դ�㵽����������ֵ�е���Сֵ
int main()
{
	build();
	Floyd();
	FindMin();
	return 0;
}
void build() //��ʼ��
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
	//��ʼ��dist���飬��ÿ��dist����Ϊ�����
	for (Vertex i = 1; i <= N; i++)
	{
		for (Vertex j = 1; j <= N; j++)
		{
			dist[i][j] = G[i][j];
		}
	}
	for (Vertex k = 1; k <= N; k++)  //Floyd�㷨
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
int FindMax(Vertex s) //����ÿ��Դ�㵽����������ֵ
{
	int max = 0;
	for (Vertex i = 1; i <= N ; i++)
	{
		if (s != i && max < dist[s][i])
			max = dist[s][i];
	}
	return max;
}
void FindMin() //����ÿ��Դ�㵽����������ֵ�е���Сֵ
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
