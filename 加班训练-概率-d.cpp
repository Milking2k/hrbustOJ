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

const int N = 1e6+7;
int T,n,m,k,Cas;
int w[N];
double W;
double v[N],dp[N];

int main()
{
    for(read(T);T;T--){
        printf("Case %d: ",++Cas);
        scanf("%lf%d",&W,&n);
        int sum = 0;
        rep(i,1,n+1){
            scanf("%d%lf",&w[i],&v[i]);
            sum += w[i];
            v[i] = 1-v[i];
        }

        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        rep(i,1,n+1) per(j,w[i],sum+1){
            dp[j] = max(dp[j], dp[ j-w[i] ]*v[i]);
        }
        per(i,0,sum+1) if(1-dp[i] <= W) {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}

/*
3
0.04 3
1 0.02
2 0.03
3 0.05

0.10 3
1 0.03
2 0.02
3 0.05
*/
