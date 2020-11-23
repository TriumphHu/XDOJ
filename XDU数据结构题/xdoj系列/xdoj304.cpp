#include<iostream>
#include<string>
#include<algorithm>
#define MAXV 5000   //表示最大节点数
using namespace std;
int Fu[MAXV];  //用来储存每个节点的父节点
typedef struct VVAndWeight  //定义储存两个点以及点之间的边
{
	int v1;
	int v2;
	int weight;
}VVAndWeight;
//重载cmp算法，用于sort排序
bool cmp(VVAndWeight& V1, VVAndWeight& V2); 
//初始化操作，将每个节点存入Fu中
void init(int len); 
//查找v的父节点，用于后面的并查集
int findFu(int v); 
//查看两个结点是否能被合并
bool merge(int v1, int v2); 
int main()
{
	int v, e; //结点数和边数
	int totalEdge, totalWeight, flag; //分别定义边和，权值和，结束标记
	cin >> v >> e;
	VVAndWeight VV[MAXV];  //结构体数组
	totalEdge = totalWeight = flag = 0;
	init(v);
	for (int i = 1; i <= e; i++)
	{
		cin >> VV[i].v1 >> VV[i].v2 >> VV[i].weight;
	}
	sort(VV + 1, VV + 1 + e, cmp);
	for (int i = 1; i <= e; i++)
	{
		if (merge(VV[i].v1, VV[i].v2))
		{
			totalEdge++;
			totalWeight += VV[i].weight;
			if (VV[i].v1 > VV[i].v2)
			{
				cout << VV[i].v2 << " " << VV[i].v1 << " " << VV[i].weight << endl;
			}
			else
			{
				cout << VV[i].v1 << " " << VV[i].v2 << " " << VV[i].weight << endl;
			}
			
		}
		if (totalEdge == v - 1)
		{
			flag = 1;
			break;
		}
	}
	return 0;
}
bool cmp(VVAndWeight& V1, VVAndWeight& V2)
{
	return V1.weight < V2.weight;
}
void init(int len)
{
	for (int i = 1; i <= len; i++)
	{
		Fu[i] = i;
	}
}
int findFu(int v)
{
	if (v != Fu[v])   //如果当前节点的父节点不是自身
		Fu[v] = findFu(Fu[v]); //那么就去找他父节点的父节点
	return Fu[v];
}
bool merge(int v1, int v2)
{
	int Find1, Find2;
	Find1 = findFu(v1);
	Find2 = findFu(v2);
	if (Find1 == Find2) //父节点相同说明几乎可以理解成是一个点了
		return false;
	else
		Fu[Find2] = Find1;
	return true;
}
