#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
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
// head
const int N = 5e2 + 7;
const int M = 2e2 + 7;
const int INF = 0x3f3f3f3f;
int T, n, m, k,tot, ansMap[N][N];
int d[N];

struct node
{
    int u, v, w;
} E[N];
bool BellMan(int start)
{
    rep(i, 1, n + 1) d[i] = INF;

    rep(i,1,n){
        bool flag = 0;
        rep(j,1,tot+1){
            int u = E[j].u, v = E[j].v, w = E[j].w;
            if (d[v] > d[u] + w){
                flag = 1;
                d[v] = d[u] + w;
            }
        }

        if(!flag){
            break;
        }
    }

    rep(j,1,tot+1) if(d[ E[j].v] > d[E[j].u] + E[j].w) {
        return true;
    }
    return false;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (scanf("%d", &T); T;T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        
        int a, b, c;
        tot = 0;
        rep(i,1,m+1){
            scanf("%d%d%d", &a, &b, &c);
            E[tot+1].u = a;
			E[tot+1].v = b;
			E[tot+1].w = c;
            E[tot+2].u = b;
			E[tot+2].v = a;
			E[tot+2].w = c;
            tot += 2;
        }
        rep(i,1,k+1){
            scanf("%d%d%d", &a, &b, &c);
            E[tot+1].u = a;
			E[tot+1].v = b;
			E[tot+1].w = -c;
            ++tot;
        }
        if(BellMan(0))
            puts("YES");
        else
            puts("NO");
    }
        return 0;
}