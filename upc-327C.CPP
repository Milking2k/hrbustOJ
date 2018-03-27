#include <bits/stdc++.h>
using namespace std;

struct node
{
	int time;
	int cnty;// 国籍
};

queue <node> q;
node head,tail;
int book[100005];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int sum=0;
	memset(book,0,sizeof(book));
	while(n--)
	{
		int time,m;
		cin >> time >> m;
		node cnt;
		while(m--)
		{
			cnt.time = time;
			cin >> cnt.cnty;
			book[cnt.cnty]++;
			if (book[cnt.cnty] == 1) sum++;
			q.push(cnt);
		}
		head = q.front();
		tail = q.back();
		while(tail.time-head.time >= 86400)
		{
			book[head.cnty]--;
			if(book[head.cnty] == 0)sum--;
			q.pop();
			head=q.front();
		}
		printf("%d\n", sum);
	}
	return 0;
}