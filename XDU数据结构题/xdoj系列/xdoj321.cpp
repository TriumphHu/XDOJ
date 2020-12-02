#include<iostream>
#include<string>
using namespace std;
struct SubWay
{
	int data;
	int parent;
	int weight;
}subwayPic[1005];
int findParent(int i);
void mergeSubway(int v1, int v2);
int main()
{
	int n, m;
	cin >> n >> m;
	int v1, v2;
	for (int i = 1; i <= n; i++)
	{
		subwayPic[i].data = i;
		subwayPic[i].parent = i;
		subwayPic[i].weight = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> v1 >> v2;
		mergeSubway(v1, v2);
	}
	int times = -1;
	for (int i = 1; i <= n; i++)
	{
		if (subwayPic[i].weight != 0)
			times++;
	}
	cout << times;
	return 0;
}
int findParent(int i)
{
	if (i != subwayPic[i].parent)
		findParent(subwayPic[i].parent);
	else
		return subwayPic[i].parent;
}
void mergeSubway(int v1, int v2)
{
	int parentV1 = findParent(v1);
	int parentV2 = findParent(v2);
	if (parentV1 < parentV2)
	{
		subwayPic[parentV2].parent = parentV1;
		subwayPic[parentV1].weight += subwayPic[parentV2].weight;
		subwayPic[parentV2].weight = 0;
	}
	else if (parentV1 > parentV2)
	{
		subwayPic[parentV1].parent = parentV2;
		subwayPic[parentV2].weight += subwayPic[parentV1].weight;
		subwayPic[parentV1].weight = 0;
	}
}
