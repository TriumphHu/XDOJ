#include<iostream>
#include<string>
#include "Link.h"
#include<stack>
void DecToAny(int Dec,int Any); //��ʮ����ת����������ƣ�С��ʮ
int main()
{
	DecToAny(666,2);
	return 0;
}
void DecToAny(int Dec, int Any) //��ʮ����ת����������ƣ�С��ʮ
{
	stack<int> stk;
	int temp;
	while (Dec)
	{
		stk.push(Dec % Any);
		Dec /= Any;
	}
	while (stk.size())
	{
		temp = stk.top();
		stk.pop();
		cout << temp;
	}
	cout << endl;

}