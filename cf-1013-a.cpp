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

int n,t,m;
int main()
{
    ll sum1=0,sum2=0;
    int x;

    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",&x);
        sum1 += x;
    }
    rep(i,1,n+1){
        scanf("%d",&x);
        sum2 += x;
    }

    if(sum1<sum2){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }


    return 0;
}


