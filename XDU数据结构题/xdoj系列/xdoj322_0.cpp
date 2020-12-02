#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n,Max;
int Graphic[105][105] = {};  //ͼ���ڽӾ���
int InDegree[105] = {};		 //���
int OutDegree[105] = {};	 //����
int EarlyTime[105] = {};     //�������ʱ��
void init();                 //��ʼ��
bool TopSort();				 //��������
int main()
{
	init();
	if (TopSort())
		cout << Max << endl;
	else
		cout << "NO" << endl;
	return 0;
}
void init()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> Graphic[i][j];
			if (Graphic[i][j] != 0)
			{
				OutDegree[i]++;
				InDegree[j]++;
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
			EarlyTime[i] = 0;
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
				EarlyTime[i] = max(EarlyTime[i], EarlyTime[v] + Graphic[v][i]);
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
		Max = 0;
		for (int i = 1; i <= n; i++)
		{
			Max = max(Max, EarlyTime[i]);
		}
		return true;
	}
}
