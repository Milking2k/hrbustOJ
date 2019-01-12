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

const int N = 1e3+7;
int t,n,m;
int a[N];
int b[N];
int c[10007];
int vis[N];

int main()
{
    scanf("%d%d",&n,&m);
    rep(i,1,n+1){
        scanf("%d",a+i);
    }
    rep(i,1,n+1){
        scanf("%d",b+i);
    }

    rep(i,1,2*n){
        if(i%2==1) c[i] = b[i/2+1];
        else c[i] = a[i/2+1];
    }c[2*n] = a[1];

    double ans = m;
    rep(i,1,2*n+1){
        if(c[i]-1 <= 0) return !printf("-1\n");
        ans = ans*c[i]/(c[i]-1);
    }

    printf("%.10f\n",ans - m);
    return 0;
}


