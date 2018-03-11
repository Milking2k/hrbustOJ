#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
#define MAXN 1003
using namespace std;
struct people
{
	int height;
	string name;
};
int main(int argc, char const *argv[])
{
	struct people student[1003];
	int times;
	cin >>times;
	while(times--)
	{
		int stuNum;
		cin >> stuNum;
		for (int i = 0; i < stuNum; ++i)
		{
			cin >> student[i].name >> student[i].height;
		}
		int max = 0;
		for (int i = 0; i < stuNum; ++i)
		{
			if (student[i].height > student[max].height)
			{
				max = i;
			}
		}
		cout << student[max].name << endl;

	}
	return 0;
}