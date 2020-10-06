#include<iostream>
#include<string>
#include<stack>
#include<iomanip>
#define MAXLENGTH 100
using namespace std;
typedef int MazeType[MAXLENGTH][MAXLENGTH];
struct PositionXY  //�Թ�������
{
	int x;
	int y;
};
struct SElemType  //����ջ��Ԫ������ 
{
	PositionXY seat; //ͨ���ڵ�ͼ�ϵ�����
	int di; //��һ�����ߵķ���1,2,3,4�ֱ�Ϊ��������
};
MazeType m; //�����Թ�����
PositionXY start;//������㣬�յ�
PositionXY endd; //endʱ��ʶ�𣬿�������ΪԴ����������ؼ���
int MazeDi[10000] = {}; //����������һλ�õķ���
int num = 0; //���������
bool IsPass(PositionXY b); //�ж�b���·���Ƿ��ͨ
int curstep = 2; //��ǰ�߹���·����ֵΪ2
void FootPrint(PositionXY b); //��b���·�����и�ֵ
void PrintMaze(int x, int y); //����Թ�
void StdPrint2(int x, int y); //��׼����ڶ��γ���
PositionXY NextPos(PositionXY b, int di);//���ݵ�ǰλ�ü��ƶ����򣬷�����һλ��
void MarkPrint(PositionXY b); //����·����ֵΪ-1����ʾ����ͨ·
bool MazePath(PositionXY start, PositionXY endd); //����Թ��ĺ��������������յ㣬����·���򷵻�true�����򷵻�false
void init(int x, int y, int mm, int nn);//��ʼ���Թ�
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
	PositionXY direc[5] = { {0,0},{0,1},{1,0},{0,-1},{-1,0} }; //��һλ�õ����꣬1234��������
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

	stack<SElemType> s; //����һ�������������͵�ջ
	PositionXY curpos; //��ǰλ��
	SElemType e;
	curpos = start;
	do
	{
		if (IsPass(curpos)) //�����ͨ��
		{
			FootPrint(curpos); //����������Ϊ��ͨ������ֵΪ2��������ʱ��

			e.seat.x = curpos.x; //���õ����긳ֵ��e���ٰ�e��ջ
			e.seat.y = curpos.y;
			e.di = 1; //���e��di������һ���µķ���
			s.push(e);
			MazeDi[num] = e.di;
			num++;
			if (curpos.x == endd.x && curpos.y == endd.y)
				return true;
			curpos = NextPos(curpos, e.di); //������һ��λ��

		}
		else //�����·�в�ͨ
		{
			if (!s.empty())
			{
				e = s.top(); //����ǰһ��·����ɾ����ɾ������Ϊǰһ��·����di����ָ����һ������Ĳ�����ָ��������������ߵ�·��
				s.pop();
				num--;
				MazeDi[num] = 0;

				while (e.di == 5 && !s.empty()) //���di������5�˻��ߵ���һ����˵�����ܶ�������
				{
					MarkPrint(e.seat); //���õ㸳ֵΪ-1����־��·��ͨ
					e = s.top(); //�˻�ǰһ��
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