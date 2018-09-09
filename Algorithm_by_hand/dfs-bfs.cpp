#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n;
int e[10][10];
int book[10];
struct node
{
	int x,s;

};
queue<node> q;
void init()
{//对输入的数组初始化
	return;
}
void dfs(int cur, int distance)
{
	// if() 判断退出条件：一般为到达最长步数、边界
	// if() 判断是否到达终点
	for (int i = 0; i < n; ++i) // 循环所有方向、所有能走的路
	{
		if (e[cur][i] != inf && book[i] == 0) 
		{// 循环内二次判断是否确实可以能走，以及判断是否没有走过
		
			// 标记已走过
			// 递归
			// 取消标记已走过
		}
	}
	return;
}
int bfs()
{
	init();
	int flag=0;
	// 开始位置start，结束位置end
	int start,end;
	cin >> start >> end;

	struct node cnt;// 出队的中间node
	struct node adcnt;// 入队的中间node

	cnt.x = start;
	cnt.s = 0;
	q.push(cnt);// 吧第一个元素入队开始循环
	while(!q.empty())// 每次循环都会有许多node入队和出队，
	{// 当队伍里有元素就代表有元素没有遍历到
		cnt = q.front();// 去除当前的元素进行循环遍历
		for (int i = 0; i < n; ++i)
		{// 第一次循环所有的路径、方向
			if (e[cnt.x][i] != inf && book[i] == 0) 
			{// 再次判断这条路是否可以走：包括遇到路障、边界、已经走过
				adcnt.x = i;
				adcnt.s += 1;
				q.push(adcnt);
				book[i] = 1;
				//可以走这条路，更新这个点的长度、更新已经走过、并把它入队				
			}
			if (cnt.x == end)//判断刚刚更新的那条个路是不是已经到终点了
			{// 一般这个条件会适用于走迷宫的问题
				flag = 1;
				break;
			}
		}
		if(flag) break;
		q.pop();
	}


}


int main(int argc, char const *argv[])
{
	
	return 0;
}