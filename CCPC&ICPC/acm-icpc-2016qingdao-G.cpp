#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=5e4+3;
struct Min_cost_flow {
    int T,S;
    double ans=0;
    double ans1=0;
    int vis[maxn],vis2[maxn],to[maxn];
    int head[maxn],next[maxn];
    int hd1[maxn],nt[maxn];
    double ct1[maxn],d1[maxn];
    double w[maxn],w1[maxn];
    double cost[maxn],d[maxn];
    int tot=2;
    int tot1=2;
    int inf=0x7fffffff;
    void init(int _s,int _t) {
        S=_s;
        T=_t;
        memset(head,0,sizeof(head));
        ans=0;
        tot=2;
        tot1=2;
    }
    void add(int u,int v,int cap,double co) {
        cost[tot]=co;
        w[tot]=cap;
        w1[tot]=cap;
        to[tot]=v;
        next[tot]=head[u];
        head[u]=tot++;

        cost[tot]=-co;
        w[tot]=0;
        w1[tot]=0;
        to[tot]=u;
        next[tot]=head[v];
        head[v]=tot++;

    }
    bool spfa() {
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        for(int i=0;i<=T;i++) {
            d[i]=inf;
        }
        queue<int>q;
        q.push(S);
        d[S]=0;
        vis[S]=1;
        while(!q.empty()) {
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int i=head[u];i;i=next[i]) {
                int v=to[i];
                if(w[i] && d[v]>d[u]+cost[i]) {
                    d[v]=d[u]+cost[i];
                    if(!vis[v]) {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return d[T]<inf;
    }
    double get() {
        double ret=1;
        for(int i=1;i<T;i++) {
            for(int j=head[i];j;j=next[j]) {
                if(w[j] != w1[j] && cost[j]!=0 && cost[j]>0) {
                    ret*=cost[j];
//                    cout<<cost[j]<<endl;
                }
            }
        }
//        cout<<ret<<endl;
        return ret;
    }
    double dfs(int u,double f) {
        if(u==T) {
            ans+=d[u]*f;
            return f;
        }
        double res=0;
        vis2[u]=1;
        for(int i=head[u];i;i=next[i])
        {
            int v=to[i];
            if(w[i] && !vis2[v] && d[v]==d[u]+cost[i]) {
                double temp=dfs(v,min(f-res,w[i]));
                w[i]-=temp;
                w[i^1]+=temp;
                res+=temp;
                if(res==f)return res;
            }
        }
        return res;
    }

    double MCMF() {
        while(spfa())ans1+=dfs(S,inf);
        return ans;
    }
}mcmf;
int s[maxn],b[maxn];
int f[maxn],t[maxn],c[maxn],id[maxn];
double p[maxn];
int main() {
    int T;
    read(T);
    while(T--) {
        int n,m;
        read(n),read(m);
        int sum=0;
        for(int i=1;i<=n;i++) {
            read(s[i]);
            read(b[i]);
            if(s[i]>=b[i]) {
                s[i]-=b[i];
                b[i]=0;
            }
            else {
                b[i]-=s[i];
                s[i]=0;
            }
            sum+=s[i];
        }
        int S=0,T=n+1;
        mcmf.init(S,T);
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d%lf",&f[i],&t[i],&c[i],&p[i]);
            mcmf.add(f[i],t[i],c[i]-1,p[i]);
            mcmf.add(f[i],t[i],1,0);
        }
        for(int i=1;i<=n;i++) {
            mcmf.add(S,i,s[i],0);
            mcmf.add(i,T,b[i],0);
        }
        double p=mcmf.MCMF();
//        cout<<p<<endl;
        double ans=mcmf.get();
        printf("%.2f\n",1.0-ans);


    }
}