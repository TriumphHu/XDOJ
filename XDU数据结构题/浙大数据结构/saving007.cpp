#include<iostream>
#include<string>
#include<queue>
#define MaxVertex 105
using namespace std;
struct Node  //存鳄鱼坐标
{
	int hor;   //横坐标
	int ver;   //纵坐标
	bool visit; //是否能被访问
	bool safe; //是否能上岸
	bool jump; //第一步是否能上去
};
int N;  //鳄鱼数
int D;  //跳跃距离
bool isSafe; //是否上岸
Node G[MaxVertex];
const double diameter = 15; //直径

double getLen(int x1, int y1, int x2, int y2); //计算两点之间的距离
bool ashore(int x, int y); //计算该鳄鱼能否到岸边
void getSafe(); //确认鳄鱼是否安全（“能上岸”）
void getJump(); //确认哪些鳄鱼是可以第一步跳上去的
void init(); //初始化
void BFS(int v); //广度优先搜索
void listCompoent(); //遍历所有第一步能跳到的鳄鱼
int main()
{
	init();
	listCompoent();
	return 0;
}
double getLen(int x1, int y1, int x2, int y2) //计算两点之间的距离
{
	return sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
}
bool ashore(int x, int y) //计算该鳄鱼能否到岸边
{
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y + 50) <= D || abs(y - 50) <= D)
		return true;
	return false;
}
void getSafe() //确认鳄鱼是否安全（“能上岸”）
{
	for (int i = 0; i < N; i++)
	{
		if (ashore((G[i].hor), G[i].ver))
			G[i].safe = true;
		else
			G[i].safe = false;
	}
}
void getJump() //确认哪些鳄鱼是可以第一步跳上去的
{
	for (int i = 0; i < N; i++)
	{
		if (getLen(G[i].hor, G[i].ver, 0, 0) <= D + diameter / 2)
			G[i].jump = true;
		else
			G[i].jump = false;
	}
}
void init() //初始化
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
void BFS(int v) //广度优先搜索
{
	queue<Node> q;
	Node temp;
	G[v].visit = true;
	q.push(G[v]);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp.safe)  //如果能上岸
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
void listCompoent() //遍历所有第一步能跳到的鳄鱼
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
