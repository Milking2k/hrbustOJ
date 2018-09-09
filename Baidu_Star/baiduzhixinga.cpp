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
const int N = 1e5+7;
int T,n,m,tot;
ll a[N];
vector<int> son[N];
priority_queue<int, vector<int>, less < int > > vv[N];
priority_queue<int, vector<int>, greater < int > > vv2[N];

void solve()
{
    ll maxnum=0,minnum=0,o=0,p=0;
    maxnum = max(maxnum, a[1]);
    minnum = min(minnum, a[1]);
    per(i,1,n){
        if(!vv[i].empty()){
            o = vv[i].top();
            vv[i].pop();
            maxnum = max(maxnum+o, maxnum);
        }
        if(!vv[i].empty()){
            o = vv[i].top();
            vv[i].pop();
            p = max(p,o);
        }
    }

    maxnum = max(maxnum, maxnum+p);
    p =0;
    per(i,1,n){
        if(!vv2[i].empty()){
            o = vv2[i].top();
            vv2[i].pop();
            minnum = min(minnum+o, minnum);
        }
        if(!vv2[i].empty()){
            o = vv2[i].top();
            vv2[i].pop();
            p = min(p,o);
        }
    }
    minnum = min(minnum,minnum+p);
    printf("%I64d %I64d\n",maxnum,minnum);
}

int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d",&n);
        rep(i,1,n+1){
            while(vv[i].size()) vv[i].pop();
            while(vv2[i].size()) vv2[i].pop();
            son[i].clear();
        }

        rep(i,2,n+1){
            int x;
            scanf("%d",&x);
            son[x].pb(i);
        }
        rep(i,1,n+1) scanf("%lld",&a[i]);
//        vv[totbro].push(a[1]);
//        vv2[totbro].push(a[1]);

        rep(i,1,n+1){
            rep(j,0,son[i].size()){
                vv[i].push(a[son[i][j]]);
                vv2[i].push(a[son[i][j]]);
//                printf("ss:%lld\n",a[son[i][j]]);
            }
        }
        solve();
    }
    return 0;
}

