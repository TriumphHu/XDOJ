#include<iostream>
#include<string>
using namespace std;
int queue1[5005];
int main()
{
	int n, out = 1, flag = 2, in = 1, length;
	cin >> n;
	length = n;
	for (int i = 1; i <= n; i++)
	{
		queue1[i] = 1;
	}
	if (n > 3)
	{
		while (length > 3)
		{
			if (flag == 2) //��һ�μ��2
			{
				for (; in <= n;)   //forѭ���ڽ����ж�
				{
					if (queue1[in] == 1)
					{
						if (out == 2)
						{
							queue1[in] = 0;
							length--;
							
							out = 0;
						}

						out++;
					}
					in++;

				}
				in = 1;    //����forѭ��
				flag = 3;
				out = 1;
			}
			else if (flag == 3) //�ڶ��μ��3
			{
				for (; in <= n;)
				{
					if (queue1[in] == 1)
					{

						if (out == 3)
						{
							queue1[in] = 0;
							length--;
							
							out = 0;
						}

						out++;
					}
					in++;

				}
				in = 1;
				flag = 2;
				out = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		if (queue1[i] == 1)
			cout << i << " ";
	}
	return 0;
}