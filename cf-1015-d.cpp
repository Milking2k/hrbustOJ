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


ll n,m,k,s;
ll cur=1;
int main()
{
    scanf("%lld%lld%lld",&n,&k,&s);
    if( k>s || (n-1) * k < s){
        printf("NO\n");
    }
    else {
        printf("YES\n");
        while(k > 0) {
            ll cnt = min(n-1, s-k+1);
            cur = cur-cnt>0 ? cur-cnt : cur+cnt;
            printf("%lld ",cur);
            s -= cnt;
            k--;
        }
    }
    return 0;
}
