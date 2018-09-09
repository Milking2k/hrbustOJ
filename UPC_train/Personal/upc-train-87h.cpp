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
int t,n,m;
int a[N]={0, 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, 1365, 2730};

void init()
{
    for(int i=5;i<1e5+7;i++){
        if(i%2==1)a[i] = 2*a[i-1]+1;
        else a[i] = 2*a[i-1];
    }
}

int main()
{
    init();
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}


