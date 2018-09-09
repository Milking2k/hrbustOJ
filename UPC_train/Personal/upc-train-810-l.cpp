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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 207;
int n;
int a[N];
int b2[N];
void init()
{
    b2[0] = 1;
    rep(i,1,35){
        b2[i] = b2[i-1]*2;
    }
}

int main()
{
    init();

    scanf("%d",&n);
    rep(i,1,n+1){
        scanf("%d",a+i);
    }
    int minans=0x3f3f3f3f;
    rep(i,1,n+1){
        int cnt = 0;
        rep(j,1,32){
            if(a[i] % b2[j] != 0) break;
            cnt++;
        }
        minans = min(minans, cnt);
    }
    printf("%d",minans);
    return 0;
}

