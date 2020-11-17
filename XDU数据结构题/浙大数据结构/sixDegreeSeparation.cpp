#include<iostream>
#include<string>
#include<queue>
#define MaxVertex 10005
typedef int vertex;
typedef struct Node* AdjList;
using namespace std;
struct Node
{
	vertex Adjv; //��ǰ�±�
	AdjList Next; //��һ��
};
AdjList G[MaxVertex];
bool visit[MaxVertex]; //�Ƿ����
int N; //�ڵ���
int M; //����
void InitVisit(); //��ʼ������״̬
void Init(); //��ʼ��
int BFS(vertex v);
void Output(double result, int i);
void SDS();
int main()
{
	Init();
	SDS();
	return 0;
}
void InitVisit() //��ʼ������״̬
{
	for (int i = 1; i <= N; i++)
	{
		visit[i] = false;
	}
}
void Init() //��ʼ��
{
	vertex v1, v2;
	AdjList NewNode;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)  //��ʼ����
	{
		G[i] = (AdjList)malloc(sizeof(struct Node));
		G[i]->Adjv = i;
		G[i]->Next = NULL; 
	}
	for (int i = 0; i < M; i++) //��ʼ����
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
	int last = v; //�ò����һ�η��ʵĽ��
	int tail = v; //ÿ���ڱ�Ľ��
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
				tail = node->Adjv; //ÿ�θ��¸ý��
			}
			node = node->Next;
		}
		//����õ�ǰ�����������һ�����
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
