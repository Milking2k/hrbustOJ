//最少转机
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
	int x,s;
};

int main(int argc, char const *argv[])
{
	struct node queue[2501];//队列
	int book[51] = {0};//标记访问数组
	int e[51][51];//储存
	int head,tail;//队列的头尾
	int cur;//循环中当前队列的头的x值
	int flag=0;//标志是否找到目标
	int startx,n,m,end;//开始结束,图的大小
	cin >> n >> m >> startx >> end;

	// memset(e,99999999,sizeof(e));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (i==j)
			{
				e[i][j] = 0;//无向图轴对称
			}
			else{
				e[i][j] = 99999999;
			}
		}
	}
	int a,b;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;//无向图轴对称
	}
	//开始计算前的初始化
	head = 1;
	tail = 1;
	//将源入队
	queue[tail].x = startx;
	queue[tail].s = 0;
	tail++;
	book[startx] = 1;
	//开始计算
	while(head < tail)
	{
		cur = queue[head].x;//获取当前队列头的x
		for (int i = 1; i <= n; ++i)
		{
			if (e[cur][i] != 99999999 && book[i] == 0)//如果有路,并且目标未被访问
			{
				queue[tail].x = i;
				queue[tail].s = queue[head].s+1;
				tail++;
				book[i] = 1;
			}
			if (queue[tail-1].x == end)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			break;
		}
		head++;//出队操作
	}
	printf("%d\n", queue[tail-1].s);

	return 0;
}