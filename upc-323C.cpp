// 螺旋矩阵
// 现给出矩阵大小n以及i和j，请你求出该矩阵中第i行第j列的数是多少。

// 这道题非常暴力
// 先求出了每一圈的最大的数，在找到需要寻找的那一圈，进行从小到达循环
// 由于想了很久x和y的关系。。为了节省时间直接模拟了一遍。


#include <bits/stdc++.h>
using namespace std;
int count(int n,int x,int y)// 模拟当前这个圈的增加方式
{
	int ans=0;
	int i,j;
	j=1;
	for (i = 1; i <= n; ++i)
	{
		ans++;
		if (i==x && j==y)
		{
			return ans;
		}
	}
	i--;
	for (j = 1+1; j <=n; ++j)
	{
		ans++;
		if (i==x && j==y)
		{
			return ans;
		}
	}
	j--;
	for (i = n-1; i > 0; --i)
	{
		ans++;
		if (i==x && j==y)
		{
			return ans;
		}
	}
	i++;
	for (j = n-1; j > 0; --j)
	{
		ans++;
		if (i==x && j==y)
		{
			return ans;
		}
	}
	return ans;
}
int toCur(int a,int n)// 取得减去外圈后的正确坐标
{
	if (a <= (n/2 + n%2))
	{
		a = a-1;
	}else{
		a = n-a;
	}
	return a;
}
int main(int argc, char const *argv[])
{
	int n,x,y;
	cin >> n >> y >> x;
	int a[15001];
	for (int i = 1; i <= n/2+n%2; ++i)
	{
		a[i] = a[i-1] + 4*(n-2*(i-1))-4;
	}
	int minCeng = min(toCur(x,n),toCur(y,n));// 得到应该减去的外层圈数
	int ans = a[minCeng] + count(n-2*minCeng,x-minCeng,y-minCeng);// 外层数字的总和加上内圈模拟的值得到答案
	printf("%d\n", ans);
	return 0;
}