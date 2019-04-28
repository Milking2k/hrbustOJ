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
const int MXBIT = 30;
int T,n,m;
int sum[N], l[N], r[N], q[N], ans[N], tree[4*N];

inline void Build(int v, int l, int r)
{
    if(l + 1 == r) {
        tree[v] = ans[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(v * 2, l, mid);
    Build(v * 2 + 1, mid, r);
    tree[v] = tree[v * 2] & tree[v * 2 + 1];
}

inline int query(int v, int l, int r, int L, int R) {
    if(l == L && r == R)
        return tree[v];

    int mid = (L + R) >> 1;
    int ans = (1ll << MXBIT) - 1;
    if(l < mid)
        ans &= query(v * 2, l, min(r, mid), L, mid);
    if(r > mid)
        ans &= query(v * 2 + 1, max(l, mid), r, mid, R);

    return ans;
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> l[i] >> r[i] >> q[i];
        l[i]--;
    }
    rep(bit,0,MXBIT+1) {
        rep(i, 0, n + 1) sum[i] = 0;
        rep(i, 0, m) {
            if ((q[i] >> bit) & 1) {
                sum[l[i]]++;
                sum[r[i]]--;
            }
        }
        rep(i, 0, n) {
            if(i > 0)
                sum[i] += sum[i - 1];
            if(sum[i] > 0)
                ans[i] |= (1ll << bit);
        }
    }
    Build(1, 0, n);
    rep(i, 0, m){
        if(query(1,l[i],r[i],0,n) != q[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    rep(i, 0, n-1) {
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[n - 1]);

    return 0;
}
/*

*/