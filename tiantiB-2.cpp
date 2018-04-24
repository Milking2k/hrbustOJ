#include<bits/stdc++.h>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,z) scanf("%d%d",&x,&y,&z)
#define ll long long int

int n;
int vis[1005];
int emt[1005];
int top;


int main()
{
	// freopen("in.txt","r",stdin);
    rd(n);
    top=0;
    for (int i = 0; i < n; ++i)
    {
    	int cnt;
    	rd(cnt);
    	if(!vis[cnt])emt[top++]=cnt, vis[cnt]=1;
    }
    sort(emt,emt+top);
    printf("%d\n", top);
    for (int i = 0; i < top; ++i)
    {
    	printf("%d", emt[i]);
    	i!=n?printf(" "):printf("\n");
    }

    return 0;
}