/*
    给定一张N个点M条边的有向无环图，分别统计从每个点出发能够到达的点的数量
    N,M<3e4
*/
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
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n=x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 3e4+7;
int T,n,m,k;

int head[N<<1],ver[N<<1],next[N<<1],dep[N<<1],tot;
void add(int x, int y){
    ver[++tot] = y, next[tot] = head[x], head[x] = tot, dep[y]++;
}

int a[N<<1];
int cnt=0;
void topsort(){
    queue < int > q;
    rep(i,1,n+1){
        if(dep[i]==0) q.push(i);
    }
    while(q.size()){
        int x = q.front();q.pop();
        a[++cnt] = x;
        for(int i = head[x];i;i = next[i]){
            int y = ver[i];
            if(--dep[y] == 0) q.push(y);
        }
    }
}

bitset < N > f[N];
void solve()
{
    per(i,1,cnt+1){
        int x = a[i];
        f[x][x] = 1;
        for(int i = head[x];i;i=next[i]){
           int y = ver[i];
           f[x] |= f[y];
        }
    }
}


int main()
{
    read(n);
    read(m);
    rep(i,1,m+1){
        int x,y;
        read(x),read(y);
        add(x,y);
    }

    topsort();

    solve();

    rep(i,1,n+1) printf("%d\n",f[i].count());

    return 0;
}

