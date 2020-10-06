#include<iostream>
#include<string>
#include<stack>
#include<iomanip>
#define MAXLENGTH 100
using namespace std;
typedef int MazeType[MAXLENGTH][MAXLENGTH];
struct PositionXY  //迷宫的坐标
{
	int x;
	int y;
};
struct SElemType  //定义栈的元素类型 
{
	PositionXY seat; //通道在地图上的坐标
	int di; //下一个行走的方向，1,2,3,4分别为东南西北
};
MazeType m; //定义迷宫数组
PositionXY start;//定义起点，终点
PositionXY endd; //end时不识别，可能是因为源码里有这个关键字
int MazeDi[10000] = {}; //储存行走下一位置的方向
int num = 0; //数组迭代器
bool IsPass(PositionXY b); //判断b点的路径是否可通
int curstep = 2; //当前走过的路径赋值为2
void FootPrint(PositionXY b); //将b点的路径进行赋值
void PrintMaze(int x, int y); //输出迷宫
void StdPrint2(int x, int y); //标准输出第二次尝试
PositionXY NextPos(PositionXY b, int di);//根据当前位置及移动方向，返回下一位置
void MarkPrint(PositionXY b); //将该路径赋值为-1，表示不可通路
bool MazePath(PositionXY start, PositionXY endd); //求解迷宫的函数，输入起点和终点，若有路径则返回true，否则返回false
void init(int x, int y, int mm, int nn);//初始化迷宫
int main()
{
	int x, y, mm, nn;
	cin >> x >> y >> mm >> nn;
	init(x, y, mm, nn);
	/*PrintMaze(x + 2, y + 2);
	cout << "----------------------"<< endl;*/
	if (MazePath(start, endd))
	{
		//PrintMaze(x + 2, y + 2);
		StdPrint2(mm, nn);
	}
	else
		cout << "no" << endl;
	return 0;
}
void init(int x, int y, int mm, int nn)
{

	start.x = mm;
	start.y = nn;
	cin >> endd.x >> endd.y;
	start.x;
	start.y;
	endd.x;
	endd.y;

	for (int i = 0; i < x + 2; i++)
	{
		for (int j = 0; j < y + 2; j++)
		{
			if (i == x + 1 || j == y + 1)
				m[i][j] = 1;
			else if (i == 0 || j == 0)
				m[i][j] = 1;
			else
				cin >> m[i][j];
		}
	}
}
bool IsPass(PositionXY b)
{
	if (m[b.x][b.y] == 0)
		return true;
	return false;
}
void FootPrint(PositionXY b)
{
	m[b.x][b.y] = curstep;
}
PositionXY NextPos(PositionXY b, int di)
{
	di--;
	PositionXY direc[5] = { {0,0},{0,1},{1,0},{0,-1},{-1,0} }; //下一位置的坐标，1234东南西北
	b.x += direc[di].x;
	b.y += direc[di].y;
	return b;
}
void MarkPrint(PositionXY b)
{
	m[b.x][b.y] = -1;
}
bool MazePath(PositionXY start, PositionXY end)
{

	stack<SElemType> s; //创建一个储存坐标类型的栈
	PositionXY curpos; //当前位置
	SElemType e;
	curpos = start;
	do
	{
		if (IsPass(curpos)) //如果能通过
		{
			FootPrint(curpos); //将该坐标标记为可通过，赋值为2，最后输出时看

			e.seat.x = curpos.x; //将该点坐标赋值给e，再把e入栈
			e.seat.y = curpos.y;
			e.di = 1; //清空e的di，设置一个新的方向
			s.push(e);
			MazeDi[num] = e.di;
			num++;
			if (curpos.x == endd.x && curpos.y == endd.y)
				return true;
			curpos = NextPos(curpos, e.di); //走向下一个位置

		}
		else //如果该路行不通
		{
			if (!s.empty())
			{
				e = s.top(); //返回前一个路径并删除，删除是因为前一个路径的di（即指向下一个方向的参数）指向了这个不能行走的路径
				s.pop();
				num--;
				MazeDi[num] = 0;

				while (e.di == 5 && !s.empty()) //如果di都等于5了还走到这一步，说明四周都不能走
				{
					MarkPrint(e.seat); //将该点赋值为-1，标志此路不通
					e = s.top(); //退回前一步
					s.pop();
					num--;
					MazeDi[num] = 0;
				}
				if (e.di < 5)
				{
					e.di++;
					s.push(e);
					MazeDi[num] = e.di;
					num++;
					curpos = NextPos(e.seat, e.di);
				}
			}

		}
	} while (!s.empty());
	return false;
}
void PrintMaze(int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << setw(2) << m[i][j] << " ";
		}
		cout << endl;
	}
}
void StdPrint2(int x, int y)
{
	int first = 0;
	int step = 0;
	int m = x;
	int n = y;
	while (MazeDi[step] != 0)
	{
		if (first)
			cout << ",";
		cout << "(" << m << "," << n << ",";
		if (MazeDi[step] == 2)
		{
			n++;
		}
		else if (MazeDi[step] == 3)
		{
			m++;
		}
		else if (MazeDi[step] == 4)
		{
			n--;
		}
		else
		{
			m--;
		}
		if (step != num - 1)
		{
			cout << MazeDi[step] - 1;
			step++;
			cout << ")";

		}
		else
		{
			cout << MazeDi[step];
			cout << ")";
			return;
		}

		first++;
	}
}