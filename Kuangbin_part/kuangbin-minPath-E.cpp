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
const int N = 1e2 + 7;
const int M = 2e2 + 7;

int T,n,m,tot,E[M][2];
double d[M],C[M][2];

bool BellMan(int start, double V)
{
    rep(i, 1, n + 1) d[i] = 0;
    d[start] = V;

    rep(i,1,n){
        bool flag = 0;
        rep(j,0,tot){
            int u = E[j][0], v = E[j][1];
            if (d[v] < (d[u] - C[j][1]) * C[j][0]){
                flag = 1;
                d[v] = (d[u] - C[j][1]) * C[j][0];
            }
        }

        if(!flag){
            return false;
        }
    }

    rep(j,0,tot) if(d[E[j][1]] < (d[E[j][0]] - C[j][1])*C[j][0]) {
        return true;
    }
    return false;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int a, b,S;
    double c, d, e, f,V;
    while(~scanf("%d%d%d%lf",&n,&m,&S,&V)){
        tot = 0;
        while(m--){
            scanf("%d%d%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
            E[tot][0] = a;
            E[tot][1] = b;
            C[tot][0] = c;
            C[tot][1] = d;
            tot++;
            E[tot][0] = b;
            E[tot][1] = a;
            C[tot][0] = e;
            C[tot][1] = f;
            tot++;
        }
        if(BellMan(S,V))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}