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

const int N = 2e6+7;

int n,t,m,ret=-1;
int vis1[N],vis2[N];
int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        int x;
        scanf("%d",&x);
        if(vis1[x]) ret=0;

        if(ret && (vis1[x&m] || vis2[x])) ret = 1;

        if(ret && ret!=1 && vis2[x&m]) ret = 2;

        vis1[x] = vis2[x&m] = 1;
    }

    printf("%d\n",ret);
    return 0;
}



