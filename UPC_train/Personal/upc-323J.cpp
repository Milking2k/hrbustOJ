
// 无线网络发射器选址
// 无线网络发射器有范围。需要覆盖到尽量最多的公共场合路口

// 一开始不敢做。。第一眼以为要图论之类的知识
// 但是我发现他数据量竟然只有128
// 所以直接暴力了结果
// 先输入所有的坐标点

// 在暴力所有的点，每次循环计算圈内所有的值的和

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int d,n,x,y,k;
	cin >> d >> n;
	int a[135][135]={0};
	memset(a,0,sizeof(a));
	for (int i = 1; i <= n; ++i)
	{
			cin >> x >> y >> k;
			a[x][y] = k;
	}
	int sum=0;
	int count=0;
	int ans=0;
	for (int i = 0; i <= 128; ++i)//边界范围
	{
		for (int j = 0; j <= 128; ++j)//边界范围
		{
			sum=0;
			for (int k = max(0,i-d); k <= min(128,i+d); ++k)//边界范围
			{
				for (int l = max(0,j-d); l <= min(128,j+d); ++l)//边界范围
				{
					sum += a[k][l];	
				}
			}
			if (sum > ans)//更新最大值
			{
				ans = sum;
				count = 1;
			}else if (sum == ans)//如果相同就是有多种放的方法
			{
				count++;
			}
		}
	}

	printf("%d %d\n", count,ans);
	return 0;
}