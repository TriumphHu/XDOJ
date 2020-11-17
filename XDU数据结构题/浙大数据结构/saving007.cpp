#include<iostream>
#include<string>
#include<queue>
#define MaxVertex 105
using namespace std;
struct Node  //����������
{
	int hor;   //������
	int ver;   //������
	bool visit; //�Ƿ��ܱ�����
	bool safe; //�Ƿ����ϰ�
	bool jump; //��һ���Ƿ�����ȥ
};
int N;  //������
int D;  //��Ծ����
bool isSafe; //�Ƿ��ϰ�
Node G[MaxVertex];
const double diameter = 15; //ֱ��

double getLen(int x1, int y1, int x2, int y2); //��������֮��ľ���
bool ashore(int x, int y); //����������ܷ񵽰���
void getSafe(); //ȷ�������Ƿ�ȫ�������ϰ�����
void getJump(); //ȷ����Щ�����ǿ��Ե�һ������ȥ��
void init(); //��ʼ��
void BFS(int v); //�����������
void listCompoent(); //�������е�һ��������������
int main()
{
	init();
	listCompoent();
	return 0;
}
double getLen(int x1, int y1, int x2, int y2) //��������֮��ľ���
{
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
bool ashore(int x, int y) //����������ܷ񵽰���
{
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D)
		return true;
	return false;
}
void getSafe() //ȷ�������Ƿ�ȫ�������ϰ�����
{
	for (int i = 0; i < N; i++)
	{
		if (ashore((G[i].hor), G[i].ver))
			G[i].safe = true;
		else
			G[i].safe = false;
	}
}
void getJump() //ȷ����Щ�����ǿ��Ե�һ������ȥ��
{
	for (int i = 0; i < N; i++)
	{
		if (getLen(G[i].hor, G[i].ver, 0, 0) <= D + diameter / 2)
			G[i].jump = true;
		else
			G[i].jump = false;
	}
}
void init() //��ʼ��
{
	cin >> N >> D;
	int x, y;
	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		G[i].hor = x;
		G[i].ver = y;
		G[i].visit = false;
 	}
	getSafe();
	getJump();
	isSafe = false;
}
void BFS(int v) //�����������
{
	queue<Node> q;
	Node temp;
	G[v].visit = true;
	q.push(G[v]);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.safe)  //������ϰ�
		{
			isSafe = true;
			return;
		}
		for (int i = 0; i < N; i++)
		{
			if (getLen(temp.hor, temp.ver, G[i].hor, G[i].ver) <= D && !G[i].visit)
			{
				G[i].visit = true;
				q.push(G[i]);
			}
		}
	}
}
void listCompoent() //�������е�һ��������������
{
	for (int i = 0; i < N; i++)
	{
		if (G[i].jump)
		{
			BFS(i);
		}
	}
	if (isSafe)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
