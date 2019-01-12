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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 107;
int t,n,m,k;
int vis[N];
int main()
{
    scanf("%d%d",&n,&m);

    int ans = m;
    memset(vis,0,sizeof(vis));

    rep(i,1,n+1){
        int x,y;
        scanf("%d %d",&x,&y);

        rep(j,x,y+1){
            if(!vis[j]) ans--;
            vis[j]=1;
        }
    }
    printf("%d\n",ans);
    rep(i,1,m+1){
        if(!vis[i]){
            printf("%d ",i);
        }
    }
    return 0;
}
