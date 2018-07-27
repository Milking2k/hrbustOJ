#include<bits/stdc++.h>
#define ll long long
#define inf 2147483647
using namespace std;
int n,tot,ans,cnt,t;
int q[300005],last[300005];
struct node{
    int l,r;
}emt[300005];
struct edge{
    int to,next;
}ver[300005];
void add(int u,int v){
    ver[++tot].to=v;ver[tot].next=last[u];last[u]=tot;
}
bool cmp(node a, node b){
    return a.l<b.l||(a.l==b.l&&a.r>b.r);
}
void build()
{
    int now=emt[t].l;
    while(cnt && emt[q[cnt]].r <= now)
        cnt--;
//    printf("q[%d]:%d %d\n",cnt,q[cnt],t);
    add(q[cnt],t);
    q[++cnt]=t;
    t++;

}

void bfs()
{
    int head=0,tail=1;
    q[0]=0;
    while(head != tail)
    {
		int now=q[head];
		head++;
		ll sum=0;
		for(int i=last[now];i;i=ver[i].next)
		{
//		    printf("i:%d to:%d\n",i,ver[i].to);
		    int nowver=ver[i].to;
			sum+=emt[nowver].r-emt[nowver].l;
			q[tail++]=nowver;
		}
		if(sum==emt[now].r-emt[now].l){
            ans++;
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
		int x,r;
		scanf("%d%d",&x,&r);
		emt[i].l=x-r;
		emt[i].r=x+r;
    }
    sort(emt+1,emt+1+n,cmp);
    ans=0;
    t=1;
    while(t<=n){
        build();
    }
    bfs();
    printf("%lld\n",0ll+ans+n+1);
    return 0;
}

/*
7
1 1
3 1
5 1
7 1
2 2
4 4
6 2
q[0]:0 1
q[1]:1 2
q[2]:2 3
q[2]:2 4
q[1]:1 5
q[2]:5 6
q[2]:5 7
11

*/
