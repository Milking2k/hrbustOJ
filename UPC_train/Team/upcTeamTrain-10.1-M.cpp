#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
const int maxn=2e5+7;
const int maxm=3e6+7;
int cnt;
struct node
{
    int from,to,val,next;
}edge[maxm<<1];
int head[maxm];
LL dis[maxn];
int vis[maxn];
struct Node
{
    int val,id;
    bool operator <(const Node &b)const
    {
        if(val==b.val)return id<b.id;
        return val>b.val;
    }
};
void init()
{
    memset(head,-1,sizeof(head));
    cnt=1;
}
void addedge(int from,int to,int val)
{
    edge[cnt].from=from;
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}

void dijkstra(int s,int e)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x7f,sizeof(dis));
    Node now;
    priority_queue<Node>q;
    while(q.size())q.pop();
    now.val=0,now.id=s;
    dis[s]=0;
    q.push(now);
    while(!q.empty()){
        Node u=q.top();
        q.pop();
        if(vis[u.id])continue;
        vis[u.id]=1;
        for(int i=head[u.id];i!=-1;i=edge[i].next){
            int to=edge[i].to;
            if(dis[u.id]+edge[i].val<dis[to]){
                dis[to]=dis[u.id]+edge[i].val;
                Node pus;
                pus.id=to,pus.val=dis[to];
                q.push(pus);
            }
        }
    }
    return ;
}

LL a[maxn];
int stk[maxn],top;
int main() {
    int n,m;
    int T;
    read(T);
    int cas=1;
    while(T--) {
        read(n);
        read(m);
        init();
        top=0;
        int num=n+1;
        for(int i=1;i<=m;i++) {
            int t,l;
            read(t);
            read(l);
            for(int j=1;j<=l;j++) {
                int x;
                read(x);
                addedge(x,num,t);
                addedge(num,x,0);
            }
            num++;
        }
        dijkstra(1,n);
        for(int i=1;i<=n;i++){
            a[i]=dis[i];
//            printf("%lld ",a[i]);
        }
//        printf("\n");
        dijkstra(n,1);
        LL minn=0x3f3f3f3f3f3f3f3fLL;
        for(int i=1;i<=n;i++){
            LL as=max(a[i],dis[i]);
            if(as<=minn){
                if(as==minn){
                    stk[top++]=i;
                }
                else{
                    minn=as;
                    top=0;
                    stk[top++]=i;
                }
            }
        }
//        for(int i=1;i<=n;i++){
//            printf("%d %lld %lld\n",i,a[i],dis[i]);
//        }
//        puts("");
        printf("Case #%d: ",cas++);
        if(minn==0x3f3f3f3f3f3f3f3fLL){
            puts("Evil John");
        }
        else{
            printf("%d\n",minn);
            for(int i=0;i<top;i++){
                if(i)printf(" ");
                printf("%d",stk[i]);
            }
            puts("");
        }
    }
    return 0;
}
