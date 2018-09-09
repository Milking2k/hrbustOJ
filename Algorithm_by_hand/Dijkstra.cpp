//6个点,9条边,单向图,单源最短路径算法
#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
int main(int argc, char const *argv[])
{
	int e[15][10],dis[10];
	int book[10];
	int n,m;
	int posx,posy,posValue;
	cin >> n >> m;
	//初始化e
	memset(e,inf,sizeof(e));
	for (int i = 1; i <= n; ++i) e[i][i] = 0;//默认自己到自己路程为0
	// 读入边的权值	
	for (int i = 1; i <= m; ++i) //读边权值
	{
		cin >> posx >> posy >>  posValue;
		e[posx][posy] = posValue;
	}
	// 初始化dis->单源点到各边的最短路程
	// 默认为点1到各边的值->可以修改e[0][i]中的0的值/或者输入一个值
	for (int i = 1; i <= n; ++i)
	{
		dis[i] = e[1][i];
	}
	//初始化book标志数组
	for (int i = 1; i <= n; ++i)
	{
		book[i] = 0;
	}
	book[1] = 1;// 将自身标记为最短;

	//开始dijkstra核心循环
	for (int i = 1; i <= n-1; ++i)
	{//每次循环代表以1到最短的路为开始,寻找这个点到其他(1到其他未确认的点)的最短
		int u;
		int min = inf;
		for (int j = 1; j <= n; ++j)
		{
			if (book[j]==0 && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (int k = 1; k <= n; ++k)
		{
			if (e[u][k] < inf && dis[k] > dis[u] + e[u][k])
			{
				dis[k] = dis[u] + e[u][k];
			}
		}
	}

	//输出结果
	for (int i = 1; i <= n; ++i)
	{
		printf("%d ",dis[i]);
	}
	return 0;	
}

// 6 9
// 1 2 1
// 1 3 12
// 2 3 9
// 2 4 3
// 3 5 5
// 4 3 4
// 4 5 13
// 4 6 15
// 5 6 4