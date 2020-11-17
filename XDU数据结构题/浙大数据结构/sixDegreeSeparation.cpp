#include<iostream>
#include<string>
#include<queue>
#define MaxVertex 10005
typedef int vertex;
typedef struct Node* AdjList;
using namespace std;
struct Node
{
	vertex Adjv; //当前下标
	AdjList Next; //下一个
};
AdjList G[MaxVertex];
bool visit[MaxVertex]; //是否访问
int N; //节点数
int M; //边数
void InitVisit(); //初始化访问状态
void Init(); //初始化
int BFS(vertex v);
void Output(double result, int i);
void SDS();
int main()
{
	Init();
	SDS();
	return 0;
}
void InitVisit() //初始化访问状态
{
	for (int i = 1; i <= N; i++)
	{
		visit[i] = false;
	}
}
void Init() //初始化
{
	vertex v1, v2;
	AdjList NewNode;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)  //初始化点
	{
		G[i] = (AdjList)malloc(sizeof(struct Node));
		G[i]->Adjv = i;
		G[i]->Next = NULL; 
	}
	for (int i = 0; i < M; i++) //初始化边
	{
		cin >> v1 >> v2;
		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v2;
		NewNode->Next = G[v1]->Next;
		G[v1]->Next = NewNode;

		NewNode = (AdjList)malloc(sizeof(struct Node));
		NewNode->Adjv = v1;
		NewNode->Next = G[v2]->Next;
		G[v2]->Next = NewNode;
	}
}
int BFS(vertex v)
{
	queue<vertex> q;
	vertex temp;
	int level = 0;
	int last = v; //该层最后一次访问的结点
	int tail = v; //每次在变的结点
	AdjList node;
	visit[v] = true;
	int count = 1;
	q.push(v);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		node = G[temp]->Next;
		while (node)
		{
			if (!visit[node->Adjv])
			{
				visit[node->Adjv] = true;
				q.push(node->Adjv);
				count++;
				tail = node->Adjv; //每次更新该结点
			}
			node = node->Next;
		}
		//如果该当前结点是这层最后一个结点
		if (temp == last)
		{
			level++;
			last = tail;
		}
		if (level == 6)
			break;
	}
	return count;

}
void Output(double result, int i)
{
	cout << i << " "<<result << endl;
}
void SDS()
{
	int count;
	for (int i = 1; i <= N; i++)
	{
		InitVisit();
		count = BFS(i);
		Output((100.0 * count) / N, i);
	}
}
