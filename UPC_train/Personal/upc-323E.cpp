
// 又是一道暴力题
// 由于是重复的，所以我直接把每个人在n轮应该出的全部补全了
// 在后面直接比较就是结果

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[205];
	int b[205];
	int na,nb;
	cin >> n >> na >> nb;
	for (int i = 0; i < na; ++i)// 输入a的出拳顺序
	{
		cin >> a[i];
	}
	if (n>na)// 补全a的出拳顺序
	{
		for (int i = na; i <= n; ++i)
		{
			a[i] = a[i-na];
		}
	}
	for (int i = 0; i < nb; ++i)// 输入b的出拳顺序
	{
		cin >> b[i];
	}
	if (n>nb)// 补全b的出拳顺序
	{
		for (int i = nb; i <= n; ++i)
		{
			b[i] = b[i-nb];
		}
	}
	int counta=0,countb=0;
	for (int i = 0; i < n; ++i)// 循环判断模拟
	{
		if (a[i] == 0 && (b[i] == 2 || b[i] == 3))
		{
			counta++;
		}
		else if (a[i] == 1 && (b[i] == 3|| b[i] == 0))
		{
			counta++;
		}
		else if(a[i] == 2 && (b[i] == 4|| b[i] == 1))
		{
			counta++;
		}
		else if(a[i] == 3 &&( b[i] == 4 || b[i] == 2))
		{
			counta++;
		}
		else if(a[i] == 4 &&( b[i] == 1 || b[i] == 0))
		{
			counta++;
		}
		else if (a[i] == b[i])
		{
			// continue;
		}
		else{
			countb++;
		}
	}
	printf("%d %d\n", counta,countb);
	
	return 0;
}