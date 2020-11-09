#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#define MAXADDRESS 100000
using namespace std;
struct Node
{
	int address;
	int key;
	int next;
	int num;
}node[MAXADDRESS];
using namespace std;
bool exist[MAXADDRESS]; //�����жϾ���ֵ�Ƿ��ظ�
void init();  //��node�ṹ�������ʼ��
int compare(Node a, Node b); //�ȽϺ���������sort�ﵱ����
int main()
{
	int begin, n,address;
	int count1 = 0;
	int t = 0;
	cin >> begin >> n;
	init();
	for (int i = 0; i < n; i++)
	{	
		cin >> address;
		cin >> node[address].key >> node[address].next;
		node[address].address = address;
	}
	for (int i = begin; i != -1; i = node[i].next)
	{
		if (exist[abs(node[i].key)] == false)
		{
			exist[abs(node[i].key)] = true;
			node[i].num = count1;
			count1++;
		}
	}
	sort(node, node + MAXADDRESS, compare);
	cout << count1 << endl;
	for (t = 0; t < count1-1; t++)
	{
		cout <<setw(5) <<setfill('0')<<node[t].address << " " << node[t].key << " " << setw(5) << setfill('0')<<node[t+1].address << endl;
	}
	cout << setw(5) << setfill('0') << node[t].address << " " << node[t].key << " " << -1 << endl;
	return 0;
}
void init()
{
	for (int i = 0; i < MAXADDRESS; i++)
	{
		node[i].num = MAXADDRESS; //��node��ÿ���ڵ�num����ֵ�����ͨ��������Ƚ�
	}

}
int compare(Node a, Node b) //�ȽϺ���������sort�ﵱ����
{
	return a.num < b.num;
}
