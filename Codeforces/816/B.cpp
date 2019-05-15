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
const int N = 2e5+7;
int T,n,m,k;
int a[N];

int sum1[N], sum2[N], sum3[N];

void add(int p, int x){ //这个函数用来在树状数组中直接修改
    while(p <= N) sum1[p] += x, p += p & -p;
}
void range_add(int l, int r, int x){ //给区间[l, r]加上x
    add(l, x), add(r + 1, -x);
}
int ask(int p){ //单点查询
    int res = 0;
    while(p) res += sum1[p], p -= p & -p;
    return res;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k >> m;

    rep(i,1,n+1){
        int x, y;
        cin >> x >> y;
        range_add(x, y, 1);
    }
    rep(i,1,N+1){
        sum3[i] = sum3[i - 1];
        if(ask(i) >= k) sum3[i]++;
    }
    // rep(i,85,102){
    //     printf("%d:%d\n", i, ask(i));
    // }
    rep(i,1,m+1){
        int x, y;
        cin >> x >> y;
        // printf("%d_%d\n", x, y);
        printf("%d\n", sum3[y] - sum3[x-1]);
        // printf("%d\n",range_ask_P(x, y));
    }

    return 0;
}
/*

*/