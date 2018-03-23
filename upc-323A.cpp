// 随机生成一个正整数集合，集合中的数各不相同，然后要求学生回答：
// 其中有多少个数，恰好等于集合中另外两个（不同的）数之和

// 主要就是存每个不同的数有多少个。
// 我用b来标记了不同的两个数的和是否出现过。

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[105];// 存输入的数据
	int b[20005]={0};// 存 是否出现了 两个数据相加后的结果
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+n);// 排序后方便计算
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] == a[i+1]) // 注意，加数和被加数必须是集合中的两个不同的数
		{
			continue;
		}
		for (int j = i+1; j < n; ++j)
		{
			b[ a[i]+a[j] ] = 1;// 这里标记的是两个数相加的结果_的位置。
		}
	}
	int count=0;
	for (int i = 0; i < n; ++i)//计算最后的结果
		if (b[a[i]] == 1)count++;
	printf("%d\n", count);
	return 0;
}