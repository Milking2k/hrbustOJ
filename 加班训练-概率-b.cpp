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

const int N = 100;
int T,n,m,k,Cas;
int a[N];
double dp[N];
int main()
{
    for(read(T);T;T--){
        printf("Case %d: ",++Cas);
        read(n);
        rep(i,1,n+1){
            read(m),dp[i] = m;
        }
        per(i,1,n){
            int x = min(6,n-i);
            rep(j,1,x+1){
                dp[i] += dp[i+j]*1.0/x;
            }
        }
        printf("%.7lf\n",dp[1]);
    }
    return 0;
}
/*
3
1
101
2
10 3
3
3 6 9

*/
