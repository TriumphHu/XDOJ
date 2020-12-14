#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
struct charTimes
{
	int index[135]; //记录字符出现的位置
	int times; //字符出现的次数
	int flag; //是否输出过
}charsTimes[135];
int main()
{
	string s;
	int k, t;
	while (getline(cin,s))
	{
		for (k = 0; k < 135; k++)
		{
			charsTimes[k].times = 0;
			charsTimes[k].flag = 0;
		}
		for (k = 0; k < s.size(); k++)
		{
			charsTimes[s[k]].index[charsTimes[s[k]].times] = k;
			charsTimes[s[k]].times++;
		}
		for (k = 0; k < s.size(); k++)
		{
			if (charsTimes[s[k]].times > 1 && 0 == charsTimes[s[k]].flag)
			{
				for (t = 0; t < charsTimes[s[k]].times - 1 ; t++)
				{
					cout << s[k] << ":" << charsTimes[s[k]].index[t] << ",";
				}
				cout << s[k] << ":" << charsTimes[s[k]].index[t];
				cout << endl;
				charsTimes[s[k]].flag = 1;
			}
		}
	}

	return 0;
}