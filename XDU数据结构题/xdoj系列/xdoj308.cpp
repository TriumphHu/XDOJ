#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	stack<string> stk;
	stack<int> num;
	string temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			temp = s[i];
			while (i < s.size() && s[i + 1] != ' ')
			{
				temp += s[i + 1];
				i++;
			}
			stk.push(temp);
		}
	
	}
	int number,num1,num2,res;
	string calc;
	while (!stk.empty())
	{
		if (stk.top() != "+" && stk.top() != "-" && stk.top() != "*" && stk.top() != "/")
		{
			number = stoi(stk.top());
			num.push(number);
		}
		else
		{
			calc = stk.top();
			num1 = num.top();
			num.pop();
			num2 = num.top();
			num.pop();
			if (calc == "+")
			{
				res = num1 + num2;
			}
			else if (calc == "-")
			{
				res = num1 - num2;
			}
			else if (calc == "*")
			{
				res = num1 * num2;
			}
			else
			{
				res = num1 / num2;
			}
			num.push(res);
		}
		stk.pop();
	}
	cout << num.top() << endl;

	return 0;
}