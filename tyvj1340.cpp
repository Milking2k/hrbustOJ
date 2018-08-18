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
int T,n,m,k,half;
unsigned int w,ans,a[(1<<24)+1];
int g[50];

void dfs1(int i, unsigned int sum)
{
    if(i==half){
        a[++m] = sum;
        return ;
    }
    dfs1(i+1,sum);
    if(sum + g[i] <= w) dfs1(i+1, sum+g[i]);
}

void calc(unsigned int val)
{
    int res = w-val;
    int l = 1, r = m;
    while(l<r){
        int mid = (l+r+1)>>1;
        if(a[mid] <= res) l = mid;
        else r = mid-1;
    }
    ans = max(ans, a[l] + val);
}

void dfs2(int i, unsigned int sum)
{
    if(i==n+1){
        calc(sum);
        return ;
    }
    dfs2(i+1,sum);
    if(sum+g[i]<=w) dfs2(i+1,sum+g[i]);
}

int main()
{
    scanf("%d%d",&w,&n);
    rep(i,1,n+1) read(g[i]);

    sort(g+1,g+1+50,[](int a,int b){return a>b;});
    half = n/2+3;
    dfs1(1,0);

    sort(a+1,a+1+m);
    m = unique(a+1,a+1+m) - (a+1);
    dfs2(half,0);

    printf("%d\n",ans);

    return 0;
}
