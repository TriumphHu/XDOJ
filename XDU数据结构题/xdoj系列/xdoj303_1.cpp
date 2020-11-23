#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Pic
{
	int data;
	int parent;
	//给这里加一个weight表示该集合有多少个元素
	int weight;
}pic[200];
void init(int n);
int findParent(int n);
//将两个点合并，因为这两个点相连
void merge(int v1, int v2);
int main()
{
	int res[200] = {};
	int length = 0;
	int n, m;
	cin >> n >> m;
	init(n);
	int v1, v2;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		merge(v1, v2);
	}
	for (int i = 1; i <= n; i++)
	{
		if (pic[i].weight != 0)
			length++;
		res[i] = pic[i].weight;
	}
	cout << length << endl;
	sort(res, res + 200);
	for (int i = 0; i < 200; i++)
	{
		if (res[i] != 0)
			cout << res[i] << " ";
	}
	return 0;
}
void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		pic[i].data = i;
		pic[i].parent = i;
		pic[i].weight = 1;
	}
}
int findParent(int n)
{
	if (pic[n].parent != n)
		findParent(pic[n].parent);
	else
		return pic[n].parent;
}
void merge(int v1, int v2)
{
	int parentV1 = findParent(v1);
	int parentV2 = findParent(v2);
	if (parentV1 != parentV2)
	{
		if (parentV1 > parentV2)
		{
			pic[parentV1].parent = parentV2;
			pic[parentV2].weight += pic[parentV1].weight;
			pic[parentV1].weight = 0;
		}
		else
		{
			pic[parentV2].parent = parentV1;
			pic[parentV1].weight += pic[parentV2].weight;
			pic[parentV2].weight = 0;
		}
	}
}
