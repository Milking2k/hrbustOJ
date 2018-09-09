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

const int N = 1e5+7;
int n,m,k;
//vector <int> v;
int v[N];
int main()
{
    scanf("%d%d",&n,&m);

    ll sum1=0,sum2=0;
    int len=0;
    rep(i,1,n+1){
        int x,y;
        scanf("%d%d",&x,&y);
        sum1 += x;
        sum2 += y;

        v[len]=x-y;
        len++;
    }

    int ans = 0;
    if(sum2 > m) {
        printf("-1\n");
    }
    else {
        sort(v, v+len, [](int a, int b){return a>b;});

        ll cnt = sum1 - m;
        for(int i = 0; i < len && cnt > 0; i++,ans++){
            cnt -= v[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}


