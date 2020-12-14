#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct numGroup
{
	int flag = 0; //组内是否有数字
	int numTimes[10005];
}groupNum[10005];
int main()
{
	memset(groupNum, 0, (10005) * sizeof(groupNum[0]));
	int m, n;
	int ar1[105] = {};
	cin >> m;
	int group;
	for (int i = 0; i < m; i++)
	{
		int max = 0;
		int maxAr1 = 0;
		cin >> n;
		for (int k = 0; k < n; k++)
		{
			cin >> ar1[k];
			if (maxAr1 < ar1[k])
				maxAr1 = ar1[k];
		}
		for (int k = 0; k < n;k++)
		{
			cin >> group;
			if (group > max)
				max = group;
			groupNum[group].flag = 1;
			groupNum[group].numTimes[ar1[k]]++;
		}
		sort(ar1,ar1+n);
		for (int k = 0; k <= max; k++)
		{
			if (groupNum[k].flag != 0)
			{
				cout << k << "={";
				int temp;
				temp = ar1[0];
				for (int j = 0; j < n; )
				{
					if (temp != maxAr1)
					{
						cout << temp << "=" << groupNum[k].numTimes[temp] << ",";
					}
					else
					{
						cout << temp << "=" << groupNum[k].numTimes[temp]<<"}";
					}
					j++;
					while (j < n && ar1[j] == temp)
					{
						j++;
					}
					temp = ar1[j];
				}
				cout << endl;
			}
		}
		memset(groupNum, 0, (max+1) * sizeof(groupNum[0]));
		memset(ar1, 0, 105);
	}
	return 0;
}