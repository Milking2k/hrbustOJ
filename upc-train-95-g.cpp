#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
#define N 100010
#define X first
#define Y second
using namespace std;
typedef long long ll;

int n,m,cnt,cnt0;
int b[N],c[N],d[N],fa[N];
ll Ans;
struct Point{
    int x,y,id;
}a[N];
struct edge{
    int u,v,w;
    edge(int u=0,int v=0):u(u),v(v){}
    friend bool operator <(edge a,edge b){
        return a.w<b.w;
    }
}e[N<<3];

inline bool cmpx(Point a,Point b){
    return a.x<b.x;
}
inline bool cmpy(Point a,Point b){
    return a.y<b.y;
}
inline bool back(Point a,Point b){
    return a.id<b.id;
}
inline int query(int x){
    int Min=1<<30,r=-1;
    for(;x<=cnt;x+=x&-x) if(c[x]<Min) Min=c[x],r=d[x];
    return r;
}
inline void Add(int x,int y,int z){
    for(;x;x-=x&-x)if(y<c[x]) c[x]=y,d[x]=z;
}
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    // reaD(n);
    cin >> n >> m;
    rep(i,1,m*n+1){
        cin >> a[i].x;
        a[i].id = i;
    }
    rep(i,1,n*m+1){
        cin >> a[i].y;
    }
    n = n * m;
    rep(i,1,n+1) b[i]=a[i].y-a[i].x;

    sort(a+1,a+1+n,cmpx);
    sort(b+1,b+1+n);
    cnt=unique(b+1,b+1+n)-b-1;

    memset(c,0x7f,sizeof(c));
    memset(d,-1,sizeof(d));

    for(int i=n;i;i--){
        int x=lower_bound(b+1,b+1+cnt,a[i].y-a[i].x)-b,pos=query(x);
        if(pos>0) e[++cnt0]=edge(a[i].id,pos);
        Add(x,a[i].x+a[i].y,a[i].id);
    }

    memset(c,0x7f,sizeof(c)); 
    memset(d,-1,sizeof(d));

    rep(i,1,n+1) 
        b[i]=-a[i].x-a[i].y;

    sort(b+1,b+1+n); 
    cnt=unique(b+1,b+1+n)-b-1;

    for(int i=n;i;i--){
        int x=lower_bound(b+1,b+1+cnt,-a[i].x-a[i].y)-b,pos=query(x);
        if(pos>0) e[++cnt0]=edge(a[i].id,pos);
        Add(x,a[i].x-a[i].y,a[i].id);
    }

    sort(a+1,a+1+n,cmpy);
    memset(c,0x7f,sizeof(c));
    memset(d,-1,sizeof(d));

    rep(i,1,n+1)
        b[i]=a[i].x-a[i].y;

    sort(b+1,b+1+n); 
    cnt=unique(b+1,b+1+n)-b-1;

    for(int i=n;i;i--){
        int x=lower_bound(b+1,b+1+cnt,a[i].x-a[i].y)-b,pos=query(x);
        if(pos>0) e[++cnt0]=edge(a[i].id,pos);
        Add(x,a[i].x+a[i].y,a[i].id);
    }

    memset(c,0x7f,sizeof(c));
    memset(d,-1,sizeof(d));

    rep(i,1,n+1)
        b[i]=a[i].y+a[i].x;

    sort(b+1,b+1+n); 
    cnt=unique(b+1,b+1+n)-b-1;
    rep(i,1,n+1){
        int x=lower_bound(b+1,b+1+cnt,a[i].y+a[i].x)-b,pos=query(x);

        if(pos>0)
            e[++cnt0]=edge(a[i].id,pos);

        Add(x,a[i].x-a[i].y,a[i].id);
    }
    //mst
    sort(a+1,a+1+n,back);

    rep(i,1,cnt0+1)
        e[i].w=abs(a[e[i].u].x-a[e[i].v].x)+abs(a[e[i].u].y-a[e[i].v].y);
    sort(e+1,e+1+cnt0);

    rep(i,1,n+1) fa[i]=i;

    rep(i,1,cnt0+1){
        if(find(e[i].u)==find(e[i].v))
            continue;
        fa[find(e[i].u)]=find(e[i].v);

        Ans+=e[i].w;
    }
    cout<<Ans<<endl;
    return 0;
}