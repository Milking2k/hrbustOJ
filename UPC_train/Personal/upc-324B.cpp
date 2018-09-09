#include <bits/stdc++.h>
using namespace std;
int a[200005];
int book[200005];
int num[200005];
int ans=0x3f3f3f3f;
int curSum;  
void dfs(int i)
{
	// printf("num[%d]:%d  curSum:%d   ans:%d\n", i,num[i],curSum,ans);
    if(num[i])
    {
        if(book[i])
        {
        	// printf("ans:%d  otherans:%d\n", ans,curSum-num[i]);
        	ans = min(ans, curSum-num[i]+1);
        }
        return;  
    }
    else
    {
		num[i] = ++curSum;
		book[i] = 1;
		dfs(a[i]);
		// printf("out\n");
		book[i] = 0;
    }
    return;
}  
int main()  
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		// printf("%d  ", a[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		dfs(i);
	}
	printf("%d",ans);
}  