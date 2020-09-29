#include<iostream>
#include<string>
#include<stack>
#include<iomanip>
#define MAXLENGTH 25
using namespace std;
typedef int MazeType[MAXLENGTH][MAXLENGTH];
struct PosType  //迷宫的坐标
{
	int x;
	int y;
};
struct SElemType  //定义栈的元素类型 
{
	PosType seat; //通道在地图上的坐标
	int di; //下一个行走的方向，0,1,2,3,分别为东南西北
};
MazeType m; //定义迷宫数组
bool IsPass(PosType b); //判断b点的路径是否可通
int curstep = 2; //当前走过的路径赋值为2
void FootPrint(PosType b); //将b点的路径进行赋值
void PrintMaze(); //输出迷宫
PosType NextPos(PosType b, int di);//根据当前位置及移动方向，返回下一位置
void MarkPrint(PosType b); //将该路径赋值为-1，表示不可通路
bool MazePath(PosType start, PosType end); //求解迷宫的函数，输入起点和终点，若有路径则返回true，否则返回false
void init();//初始化迷宫
int main()
{
	init();
	if (MazePath({ 1,1 }, { 23,23 }))
		cout << "该迷宫有路径" << endl;
	else
		cout << "该迷宫没有路径！" << endl;
	PrintMaze();
	return 0;
}
void init()
{
	cout << "请输入一个" << MAXLENGTH << " X " << MAXLENGTH << "迷宫，1为墙，0为通路" << endl;
	for (int i = 0; i < MAXLENGTH; i++)
	{
		for (int j = 0; j < MAXLENGTH; j++)
		{
			cin >> m[i][j];
		}
	}
}
bool IsPass(PosType b)
{
	if (m[b.x][b.y] == 0 )
		return true;
	return false;
}
void FootPrint(PosType b)
{
	m[b.x][b.y] = curstep;
}
PosType NextPos(PosType b, int di)
{
	PosType direc[4] = { {0,1},{1,0},{0,-1},{-1,0} }; //下一位置的坐标，东南西北
	b.x += direc[di].x;
	b.y += direc[di].y;
	return b;
}
void MarkPrint(PosType b)
{
	m[b.x][b.y] = -1;
}
bool MazePath(PosType start, PosType end)
{
	stack<SElemType> s; //创建一个储存坐标类型的栈
	PosType curpos; //当前位置
	SElemType e;
	curpos = start;
	do
	{
		if (IsPass(curpos)) //如果能通过
		{
			FootPrint(curpos); //将该坐标标记为可通过，赋值为2，最后输出时看
			e.seat.x = curpos.x; //将该点坐标赋值给e，再把e入栈
			e.seat.y = curpos.y;
			e.di = 0; //清空e的di，设置一个新的方向
			s.push(e);
			if (curpos.x == end.x && curpos.y == end.y)
				return true;
			curpos = NextPos(curpos, e.di); //走向下一个位置
		}
		else //如果该路行不通
		{
			if (!s.empty())
			{
				e = s.top(); //返回前一个路径并删除，删除是因为前一个路径的di（即指向下一个方向的参数）指向了这个不能行走的路径
				s.pop();
				while (e.di == 3 && !s.empty()) //如果di都等于3了还走到这一步，说明四周都不能走
				{
					MarkPrint(e.seat); //将该点赋值为-1，标志此路不通
					e = s.top(); //退回前一步
					s.pop();
				}
				if (e.di < 3)
				{
					e.di++;
					s.push(e);
					curpos = NextPos(e.seat, e.di);
				}
			}

		}
	} while (!s.empty());
	return false;
}
void PrintMaze()
{
	for (int i = 0; i < MAXLENGTH; i++)
	{
		for (int j = 0; j < MAXLENGTH; j++)
		{
			cout<<setw(2) <<m[i][j] << " " ;
		}
		cout << endl;
	}
}