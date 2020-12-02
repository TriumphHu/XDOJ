#include<iostream>
#include<string>
#define INFINITE 10000
using namespace std;
int Graphic[105][105] = {};
int FloydPath[105][105] = {};
int N;
void init();
void Floyd();
void PathPrint(int v1, int v2, int end);
void FloydPathPrint();
void GraphicPrint();
int main()
{
	init();
	Floyd();
	//FloydPathPrint();
	int v1, v2;
	cin >> v1 >> v2;
	while (v1 != -1 && v2 != -1)
	{
		if (Graphic[v1][v2] >= INFINITE)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << Graphic[v1][v2] << endl;
			PathPrint(v1, v2, v2);
			cout << endl;
		}
		cin >> v1 >> v2;
	}
	return 0;
}
void init()
{
	cin >>N;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cin>>Graphic[i][k];
			FloydPath[i][k] = -1;
		}
	}
}
void Floyd()
{
	for (int i = 0; i < N; i++)
	{
		Graphic[i][i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Graphic[k][j] > Graphic[k][i] + Graphic[i][j])
				{
					Graphic[k][j] = Graphic[k][i] + Graphic[i][j];	
					FloydPath[k][j] = i;
				}
			}
		}
	}
}
void PathPrint(int v1, int v2, int end)
{
	if (FloydPath[v1][v2] == -1)
	{
		cout << v1 << " ";
		if (v2 == end)
			cout << end << " ";
		return;
	}
	else
	{
		PathPrint(v1,FloydPath[v1][v2], end);
		PathPrint(FloydPath[v1][v2], v2, end);
	}
}
void FloydPathPrint()
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cout << FloydPath[i][k] << " ";
		}
		cout << endl;
	}
}
void GraphicPrint()
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cout << Graphic[i][k] << " ";
		}
		cout << endl;
	}
}
