#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+7;
ll head[N];
ll ver[N];
ll edge[N];
ll Next[N];
ll d[N];
bool v[N];
int t,n,m,tot=0;
priority_queue < pair<int, int> > q;
void add(int x, int y, int z){
    ver[++tot]=y;edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}

void dijkstra(int k){
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    d[k]=0;
    q.push(make_pair(0,k));
    while(q.siz e()){
        int x = q.top().second;
        q.pop();
        if(v[x]) continue;
        v[x]=1;
        for(int i=head[x];i;i=Next[i]){
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z){
                d[y]=d[x]+z;
                q.push(make_pair(-d[y],y));
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    int q,k;
    scanf("%d %d",&q,&k);
    dijkstra(k);
    for(int i=1;i<=q;i++){
        int ask1,ask2;
        scanf("%d %d",&ask1,&ask2);
        printf("%lld\n",d[ask1]+d[ask2]);
    }

    return 0;
}

