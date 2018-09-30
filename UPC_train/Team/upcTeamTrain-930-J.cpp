#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 530600414;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef long long LL;
const LL MOD=530600414;

const int maxn=201314+7;
LL sz[maxn],cnt[maxn],pre[maxn];
LL a[maxn];
LL solve(LL x)
{
    if(x<0){
        x%=MOD;
        x+=MOD;
    }
    if(x>MOD)x%=MOD;
    return x;
}
int main()
{
    int T;
    scanf("%d",&T);
    sz[3]=3;cnt[3]=1;pre[3]=1;a[3]=0;
    sz[4]=5;cnt[4]=1;pre[4]=3;a[4]=0;
    for(int i=5;i<=201314;i++){
        sz[i]=solve(sz[i-2]+sz[i-1]);
        cnt[i]=solve(cnt[i-2]+cnt[i-1]);
        pre[i]=solve(pre[i-2]+sz[i-2]*cnt[i-1]+pre[i-1]);
        a[i]=solve(a[i-2]+solve(a[i-1]+solve(solve(cnt[i-2]*pre[i-1])+solve(solve(cnt[i-2]*sz[i-2])*cnt[i-1])-solve(pre[i-2]*cnt[i-1]))));
    }
    int cas=1;
    while(T--){
        int n;
        scanf("%d",&n);
        printf("Case #%d: %lld\n",cas++,a[n]);
    }
    return 0;
}

