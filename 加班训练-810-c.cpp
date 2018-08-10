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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 307;
int n,m,k,pre[N][N];
char s[N][N];

int getpre(int x1,int y1,int x2,int y2){
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

void solve()
{
    int ans=1<<20;
    rep(i,1,n+1)rep(j,i,n+1){
        int l=1,r=1;
        while(1){
            while(getpre(i,l,j,r) < k && r < m) r++;
            if(getpre(i,l,j,r) < k) break;
            else ans = min(ans, (j-i+1)*(r-l+1));
            ++l;
        }
    }

    printf("%d\n",ans);
}


int main()
{
    while(~scanf("%d%d%d",&n,&m,&k) && n!=0){
        rep(i,1,n+1) scanf("%s",s[i]+1);

        rep(i,1,n+1)rep(j,1,m+1){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            if(s[i][j]=='.') pre[i][j]++;
        }

        solve();

    }

    return 0;
}
