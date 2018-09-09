#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi head
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1000005;
int n,m,Q,p[N],l[N],r[N],id[N];
int tot,head[N],nxt[N],to[N],du[N];
queue<int>q;

void add(int x,int y){
    nxt[++tot]=head[x],head[x]=tot,to[tot]=y,du[y]++;
}
void extend(int i)
{
    while(1)
    {
        int now1=1,now2=1;
        if(l[i]==1)now1=0;
        if(r[i]==n)now2=0;
        if(now1)
        {
            if((!p[l[i]-1])||(p[l[i]-1]>=l[i]&&p[l[i]-1]<=r[i]))l[i]=l[id[l[i]-1]];
            else now1=0;
        }
        if(now2)
        {
            if((!p[r[i]])||(p[r[i]]>=l[i]&&p[r[i]]<=r[i]))r[i]=r[id[r[i]+1]];
            else now2=0;
        }
        if(!now1&&!now2)break;
    }
}
void topsort()
{
    rep(i,1,n+1) if(id[i]==i&&!du[i])q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();
        extend(u);
        for(int e=head[u];e;e=nxt[e])
            if(!(--du[to[e]]))q.push(to[e]);
    }
}
int main()
{
    int x,y;
    scanf("%d%d%d",&n,&m,&Q);
    while(m--) scanf("%d",&x),scanf("%d",&p[x]);

    rep(i,1,n+1) id[i]=l[i]=r[i]=i;
    rep(i,1,n+1){
        if(!p[i])
            id[i+1]=id[i];
        else
            p[i]<=i ? add(id[i+1],id[i]) : add(id[i],id[i+1]);
    }

    rep(i,1,n+1)
        l[id[i]] = min(l[id[i]],l[i]), r[id[i]] = max(r[id[i]],r[i]);

    topsort();
    rep(i,1,n+1) l[i]=l[id[i]], r[i]=r[id[i]];

    while(Q--)
    {
        scanf("%d%d",&x,&y);
        l[x] <= y && y <= r[x] ? puts("YES") : puts("NO");
    }
    return 0;
}
