#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<assert.h>
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
//head

const int N = 1e2+7;
const int M = 1e4 + 7;
const int INF = 0x3f3f3f3f;

int T,n,m;
int E[N][N];

int d[N];

char str[11];

int head[N<<1], nxt[M<<1], ver[M<<1], w[M<<1],tot;
void add(int u, int v, int z){
    ver[++tot] = v;
    w[tot] = z;
    nxt[tot] = head[u];
    head[u] = tot;
}

priority_queue<PII, vector<PII>, greater<PII> > Q;

int q[66000];
int in[N << 1];
unsigned short h, t;
void add2(int x, int y)
{
    if (y >= d[x])
        return;
    d[x] = y;
    if (!in[x])
    {
        in[x] = 1;
        if (y < d[q[h]])
            q[--h] = x;
        else
            q[++t] = x; //SLF优化
    }
}
void spfa(int S)
{ //S为源点
    int i, x;
    for (i = h = 1; i <= n; i++)
        d[i] = INF, in[i] = 0;
    add2(S, t = 0);
    while (h != t + 1)
        for (i = head[x = q[h++]], in [x] = 0; i; i = nxt[i])
            add2(ver[i], d[x] + w[i]);
}

void dijkstra(int S)
{
    int i, x;
    for (i = 1; i <= n; i++)
        d[i] = INF;
    Q.push(PII(d[S] = 0, S));
    while (!Q.empty())
    {
        PII t = Q.top();
        Q.pop();
        if (d[x = t.second] < t.first)
            continue;
        for (i = head[x]; i; i = nxt[i])
            if (d[x] + w[i] < d[ver[i]])
                Q.push(PII(d[ver[i]] = d[x] + w[i], ver[i]));
    }
}

// void dijkstra(int S)
// {
//     rep(i, 1, n + 1) d[i] = INF;
//     Q.push(PII(d[S] = 0, S));
//     while(!Q.empty()){
//         PII t = Q.top();Q.pop();
//         int x;
//         if(d[x=t.se] < t.fi) continue;
//         for (int i = head[x]; i;i=nxt[i]) if(d[x]+w[i]<d[ver[i]])Q.push(PII(d[ver[i]]=d[x]+w[i],ver[i]));
//     }
// }

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    while(~scanf("%d",&n)){
        rep(i, 0, n + 1) head[i] = 0;
        tot = 0;
        rep(i,1,n){
            rep(j,1,i+1){
                scanf("%s", str);
                if(str[0]!='x'){
                    int ans = atoi(str);
                    add(i + 1, j, ans);
                    add(j, i + 1, ans);
                }
            }
        }

        spfa(1);

        ll ans = -1;
        rep(i,2,n+1){
            if(ans < d[i])
                ans = d[i];
            // printf("%d ", d[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}