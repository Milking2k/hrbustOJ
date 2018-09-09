#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f
typedef pair<int, int>P;

struct edge{int from,to,cost;}es2[50007];
int es[2507][2507];
//vector<es2> G[10007];
int d[10007];
int n,m,w;
int pos;

void init()
{
    memset(d,0,sizeof(d));
    pos=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(es[i][j]!=INF){
                es2[pos].from = i;
                es2[pos].to = j;
                es2[pos++].cost = es[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        d[i]=min(d[i],es[1][i]);
    }
}
bool find_negative_loop()
{
    for(int i=1;i<n;i++)
    {
        bool ok=false;
        for(int j=1;j<=pos;j++)
        {
            edge e= es2[j];
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from]+e.cost;
                ok=true;
            }
        }
        if(!ok)break;
    }
    for (int i = 1; i <=pos; ++ i)
	{
		if(d[es2[i].to] > d[es2[i].from] + es2[i].cost)
			return true;
	}
    return false;
}

bool bellMan(void)
{
    bool flag;
    for (int i = 1; i < n; ++i)
    {
        flag = false;
        for (int j = 1; j <= pos; ++j)
        {
            if (d[es2[j].to] > d[es2[j].from] + es2[j].cost)//松弛
            {
                d[es2[j].to] = d[es2[j].from] + es2[j].cost;
                flag = true;
            }
        }
        if (!flag)//存在负权回路
        {
            break;
        }
    }
    for (int i = 1; i <= pos; ++ i)
    {
        if(d[es2[i].to] > d[es2[i].from] + es2[i].cost)
            return true;
    }
    return false;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<505;i++) {
            for(int j=0;j<505;j++) {
                if(i==j)es[i][j]=0;
                else es[i][j]=INF;
            }
        }
        scanf("%d%d%d",&n,&m,&w);
//        pos=0;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            es[a][b] = min(es[a][b],c);
            es[b][a] = min(es[b][a],c);
        }
        for(int i=0;i<w;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            es[a][b] = -c;
        }
        init();
        if(find_negative_loop()) printf("YES\n");
//        if(bellMan()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}