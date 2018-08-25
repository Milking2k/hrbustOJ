/*
    A Simple Problem with Integers （树状数组区间更新）
*/
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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k;
ll a[N];

struct BITS
{
    ll bits[N];
    ll bits2[N];

    void add(ll a[], int x, int d){
        while(x<=n){
            bits[x] += d;
            x += x&-x;
        }
    }

    void addblock(int l, int r ,ll val){
        add(bits2, l, val);
        add(bits2, r, -val);
        add(bits, l, val*(1-l));
        add(bits, r, val*r);
    }

    ll getsum(ll a[], int x){
        ll ret = 0;
        while(x){
            ret += a[x];
            x -= x&-x;
        }
        return ret;
    }

    ll getblocksum(int x){
        return getsum(bits2, x)*x + getsum(bits, x);
    }
}bit;


int main()
{
    while(~scanf("%d%d",&n,&m)){
        rep(i,1,n+1) scanf("%lld\n", a+i),a[i]+=a[i-1];
        char s[5];
        int x,y,val;
        scanf("%s %d %d",s,x,y);
        if(s[0]=='Q'){
            printf("%lld\n",bit.getblocksum(y)-bit.getblocksum(x) + a[y] - a[x-1]);
        }
        else{
            read(val);
            bit.addblock(x,y,val);
        }
    }
    return 0;
}