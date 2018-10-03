#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#define read(x) scanf("%d",&x)
#define debug puts("%%%%%")
using namespace std;
typedef long long LL;
const int maxn=1e4+10;
struct edge{
    int x,y,w;
    edge(int x=0,int y=0,int z=0):x(x),y(y),w(z){}
}e[maxn];
int N,M;
int fa[maxn];
int getfather(int x) {
    if(x==fa[x]) {
        return x;
    }
    else return fa[x]=getfather(fa[x]);
}
bool cmp(edge a,edge b) {
    return a.w<b.w;
}
int kruscal() {
    sort(e+1,e+1+M,cmp);
    int cnt=N;
    int ans=0;
    for(int i=1;i<=N;i++) {
        fa[i]=i;
    }
    for(int i=1;i<=M;i++) {
        int ta=getfather(e[i].x);
        int tb=getfather(e[i].y);
        if(ta!=tb) {
            fa[ta]=tb;
            ans+=e[i].w;
            if(cnt==1)break;
        }
    }
    return ans;
}

int main() {
    int T;
    read(T);
    int Cas=1;
    while(T--) {
        read(N);
        int k;
        read(k);
        M=0;
        for(int i=1;i<=k;i++) {
            int a,b,c;
            read(a),read(b),read(c);
            e[++M].w=c;
            e[M].x=a;
            e[M].y=b;
        }
        printf("Case #%d: %d meters\n",Cas++,kruscal());
    }

}
