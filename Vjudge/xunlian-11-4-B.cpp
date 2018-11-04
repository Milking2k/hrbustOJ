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
const int N = 1e2+7;
int T,n,m;
int x[N],y[N],d[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int L;
    scanf("%d", &L);

    if(L<=60){
        printf("2 %d\n", L);
        rep(i,0,L){
            printf("1 2 %d\n", i);
        }
        return 0;
    }

    int len = 0;
    while(1<<len <= L)
        ++len;

    n = len, m = 0;
    rep(i,0,len-1){
        x[++m] = i + 1;
        y[m] = i + 2;
        d[m] = 0;
        x[++m] = i + 1;
        y[m] = i + 2;
        d[m] = 1<<i;        
    }

    per(i,0,len-1){
        if(L&(1<<i)){
            x[++m] = i + 1;
            y[m] = n;
            d[m] = L >> (i + 1) << (i + 1);
        }
    }

    printf("%d %d\n", n, m);
    rep(i,1,m+1){
        printf("%d %d %d\n", x[i], y[i], d[i]);
    }
    return 0;
}