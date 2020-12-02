#include<iostream>
#include<string>
#include<queue>
using namespace std;
int InDegree[105] = {};		 //���
int OutDegree[105] = {};	 //����
int n; //�����
int Graphic[105][105] = {};
bool TopSort();
void init();
void clear();
int main()
{
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		init();
		if (TopSort())
			cout << 0;
		else
			cout << 1;
		clear();

	}
	return 0;
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			cin >> Graphic[i][k];
			if (Graphic[i][k] != 0)
			{
				OutDegree[i]++;
				InDegree[k]++;
			}
		}
	}
}

bool TopSort()
{
	int count = 0;
	queue<int> q;
	//���������Ϊ0�Ľ�����
	for (int i = 1; i <= n; i++)
	{
		if (InDegree[i] == 0)
		{
			q.push(i);
			
		}
	}
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		count++;
		for (int i = 1; i <= n; i++) //�Գ��ӵ�ÿһ���ڽӵ���з���
		{
			if (Graphic[v][i] != 0)
			{
				
				InDegree[i]--;
				if (InDegree[i] == 0)
				{
					q.push(i);
				}
			}
		}
	}
	if (count != n)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void clear()
{
	memset(Graphic, 0, 105 * 105 * sizeof(Graphic[0][0]));
	memset(InDegree, 0, 105 * sizeof(InDegree[0]));
	memset(OutDegree, 0, 105 * sizeof(OutDegree[0]));
}