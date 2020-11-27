#include<iostream>
#include<string>
using namespace std;
int main()
{
	int x, y, m, n;
	cin >> x >> y;
	while (x != 0 && y != 0)
	{
		m = x;
		n = y;
		while (m != n)
		{
			if (m > n)
				m /= 2;
			else
				n /= 2;
		}
		cout << m << endl;
		cin >> x >> y;
	}
	return 0;
}