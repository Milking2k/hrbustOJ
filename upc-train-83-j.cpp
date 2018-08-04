#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N = 1e5+7;
int t,n,m;
int a[N],b[N],c[N];
 
int main()
{
 
 
    ll sum = 0;
    scanf("%d",&n);
 
    rep(i,1,n+1) scanf("%d",a+i);
    rep(i,1,n+1) scanf("%d",b+i);
    rep(i,1,n+1) scanf("%d",c+i);
 
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    sort(c+1,c+1+n);
 
    ll an=0,cn=0;
    for(int i = 1; i<= n; i++){
        for(;an + 1 <= n && a[an+1] < b[i]; an++);
        for(;cn + 1 <= n && c[cn+1] <= b[i]; cn++);
        sum += an*(n-cn);
    }
 
    printf("%lld\n",sum);
    return 0;
}