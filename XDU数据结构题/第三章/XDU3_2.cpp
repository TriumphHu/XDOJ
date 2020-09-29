#include<iostream>
#include<string>
#include<stack>
#include<iomanip>
#define MAXLENGTH 25
using namespace std;
typedef int MazeType[MAXLENGTH][MAXLENGTH];
struct PosType  //�Թ�������
{
	int x;
	int y;
};
struct SElemType  //����ջ��Ԫ������ 
{
	PosType seat; //ͨ���ڵ�ͼ�ϵ�����
	int di; //��һ�����ߵķ���0,1,2,3,�ֱ�Ϊ��������
};
MazeType m; //�����Թ�����
bool IsPass(PosType b); //�ж�b���·���Ƿ��ͨ
int curstep = 2; //��ǰ�߹���·����ֵΪ2
void FootPrint(PosType b); //��b���·�����и�ֵ
void PrintMaze(); //����Թ�
PosType NextPos(PosType b, int di);//���ݵ�ǰλ�ü��ƶ����򣬷�����һλ��
void MarkPrint(PosType b); //����·����ֵΪ-1����ʾ����ͨ·
bool MazePath(PosType start, PosType end); //����Թ��ĺ��������������յ㣬����·���򷵻�true�����򷵻�false
void init();//��ʼ���Թ�
int main()
{
	init();
	if (MazePath({ 1,1 }, { 23,23 }))
		cout << "���Թ���·��" << endl;
	else
		cout << "���Թ�û��·����" << endl;
	PrintMaze();
	return 0;
}
void init()
{
	cout << "������һ��" << MAXLENGTH << " X " << MAXLENGTH << "�Թ���1Ϊǽ��0Ϊͨ·" << endl;
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
	PosType direc[4] = { {0,1},{1,0},{0,-1},{-1,0} }; //��һλ�õ����꣬��������
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
	stack<SElemType> s; //����һ�������������͵�ջ
	PosType curpos; //��ǰλ��
	SElemType e;
	curpos = start;
	do
	{
		if (IsPass(curpos)) //�����ͨ��
		{
			FootPrint(curpos); //����������Ϊ��ͨ������ֵΪ2��������ʱ��
			e.seat.x = curpos.x; //���õ����긳ֵ��e���ٰ�e��ջ
			e.seat.y = curpos.y;
			e.di = 0; //���e��di������һ���µķ���
			s.push(e);
			if (curpos.x == end.x && curpos.y == end.y)
				return true;
			curpos = NextPos(curpos, e.di); //������һ��λ��
		}
		else //�����·�в�ͨ
		{
			if (!s.empty())
			{
				e = s.top(); //����ǰһ��·����ɾ����ɾ������Ϊǰһ��·����di����ָ����һ������Ĳ�����ָ��������������ߵ�·��
				s.pop();
				while (e.di == 3 && !s.empty()) //���di������3�˻��ߵ���һ����˵�����ܶ�������
				{
					MarkPrint(e.seat); //���õ㸳ֵΪ-1����־��·��ͨ
					e = s.top(); //�˻�ǰһ��
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