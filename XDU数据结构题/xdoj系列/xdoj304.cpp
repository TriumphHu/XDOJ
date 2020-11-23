#include<iostream>
#include<string>
#include<algorithm>
#define MAXV 5000   //��ʾ���ڵ���
using namespace std;
int Fu[MAXV];  //��������ÿ���ڵ�ĸ��ڵ�
typedef struct VVAndWeight  //���崢���������Լ���֮��ı�
{
	int v1;
	int v2;
	int weight;
}VVAndWeight;
//����cmp�㷨������sort����
bool cmp(VVAndWeight& V1, VVAndWeight& V2); 
//��ʼ����������ÿ���ڵ����Fu��
void init(int len); 
//����v�ĸ��ڵ㣬���ں���Ĳ��鼯
int findFu(int v); 
//�鿴��������Ƿ��ܱ��ϲ�
bool merge(int v1, int v2); 
int main()
{
	int v, e; //������ͱ���
	int totalEdge, totalWeight, flag; //�ֱ���ߺͣ�Ȩֵ�ͣ��������
	cin >> v >> e;
	VVAndWeight VV[MAXV];  //�ṹ������
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
	if (v != Fu[v])   //�����ǰ�ڵ�ĸ��ڵ㲻������
		Fu[v] = findFu(Fu[v]); //��ô��ȥ�������ڵ�ĸ��ڵ�
	return Fu[v];
}
bool merge(int v1, int v2)
{
	int Find1, Find2;
	Find1 = findFu(v1);
	Find2 = findFu(v2);
	if (Find1 == Find2) //���ڵ���ͬ˵����������������һ������
		return false;
	else
		Fu[Find2] = Find1;
	return true;
}
