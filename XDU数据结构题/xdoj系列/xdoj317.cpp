#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	int n,m,begin,last;
	int tree[1005] = {};
	cin >> n;
	while (n != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> tree[i];
		}
		cin >> m;
		begin = pow(2, (m - 1)) ;
		last = pow(2, m) <= n ? pow(2, m) - 1 : n ;
		if (begin <= last)
		{
			for (int i = begin; i <= last; i++)
				cout << tree[i] << " ";
		}
		else
		{
			cout << "EMPTY";
		}
		cout << endl;
		memset(tree, 0, (n + 1) * sizeof(int));
		cin >> n;
		
	}
	
	return 0;
}