#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct student
{
	string name;
	int age;
	int grade;
}students[105];
bool cmp(student s1, student s2);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> students[i].name >> students[i].age >> students[i].grade;
	}
	sort(students, students + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << students[i].name<<" " << students[i].age <<" "<< students[i].grade;
		cout << endl;
	}
	return 0;
}
bool cmp(student s1, student s2)
{
	if (s2.grade != s1.grade)
	{
		return s2.grade < s1.grade;
	}
	else if (s2.name != s1.name)
	{
		return s2.name > s1.name;
	}
	else
		return s1.age < s2.age;
}
