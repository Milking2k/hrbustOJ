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
const int N = 2e6+7;
const int LEN = 1e5 + 7;
int T,n,m;
int sum[N];
PII a[N];
void add(int p, int x){ //这个函数用来在树状数组中直接修改
    while(p <= N) sum[p] += x, p += p & -p;
}
void range_add(int l, int r, int x){ //给区间[l, r]加上x
    add(l, x), add(r + 1, -x);
}
int ask(int p){ //单点查询
    int res = 0;
    while(p) res += sum[p], p -= p & -p;
    return res;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(sum, 0, sizeof(sum));
    cin >> n >> m;
    rep(i,1,n+1){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + 1 + n);
    rep(i,1,m+1){
        char ops[20];
        int x;
        scanf("%s%d", ops, &x);
        printf("%s_%d\n", ops, LEN+x-1);
        if(ops[0] == '<'){
            range_add(1, LEN + x - 1, 1);
        }
        else{
            range_add(LEN + x + 1, 2 * LEN, 1);
        }
        rep(i,-5,6){
            printf("%d ", ask(LEN+i));
        }
        printf("debug\n");
    }

    return 0;
}
/*

*/