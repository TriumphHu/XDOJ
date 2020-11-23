#include<iostream>
#include<string>
using namespace std;
typedef	 struct people* PeoNext;
struct people
{
	int order;
	int password;
	PeoNext pre;
	PeoNext next;
};
PeoNext init(); 
PeoNext PeoInit(PeoNext peo, int len);
void printPeo(PeoNext peo, int len);
//删除peo这个结点,返回上一个结点
PeoNext deletePeo(PeoNext peo); 
void Josephus(PeoNext peo, int m, int n);
PeoNext peo = init();
int main()
{
	int len, m;
	cin >> len >> m;
	PeoInit(peo, len);
	Josephus(peo, m, len);
	return 0;
}
PeoNext init()
{
	PeoNext people = (PeoNext)malloc(sizeof (struct people));
	people->pre = NULL;
	people->next = NULL;
	return people;
}
PeoNext PeoInit(PeoNext peo, int len)
{
	PeoNext start = peo;
	start->order = 1;
	cin >> start->password;
	PeoNext p = init();
	for (int i = 2; i <= len; i++)
	{
		p->pre = peo;
		p->order = i;
		cin >> p->password;
		peo->next = p;
		peo = p;
		if (i == len)
		{
			start->pre = peo;
			peo->next = start;
		}
		p = init();
	}
	return start;
}
void printPeo(PeoNext peo, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "peo 的序号是 " << peo->order << " peo 的密码是" << peo->password << endl;
		peo = peo->pre;
	}
}
PeoNext deletePeo(PeoNext peo)
{
	PeoNext p = peo->pre;
	p->next = peo->next;
	peo->next->pre = p;
	free(peo);
	return p;
}
void Josephus(PeoNext peo, int m, int n) 
{
	int t = 0;
	int order = 1; 
	while (t < n)
	{
		if (order == m)
		{
			m = peo->password;
			cout << peo->order<<" ";
			peo = deletePeo(peo);
			order = 0;
			t++;
		}
		if (t == n - 1)
		{
			cout << peo->order << " ";
			break;
		}
		peo = peo->next;
		
		order++;
	}
}

