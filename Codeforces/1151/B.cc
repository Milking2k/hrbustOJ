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
const int N = 500+7;
int T,n,m;
vector<PII> a[N];
int len[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int ans = 0;
    rep(i,1,n+1) {
        rep(j,1,m+1){
            int x;
            cin >> x;
            a[i].pb(mp(x, j));
        }
        sort(a[i].begin(), a[i].end());
        len[i] = unique(a[i].begin(), a[i].end(), [](PII a, PII b){return a.fi == b.fi;}) - a[i].begin();
        a[i].resize(len[i]);
        ans ^= a[i][0].first;
    }

    if(ans != 0) {
        printf("TAK\n");
        rep(i, 1, n + 1) printf("%d ", a[i][0].se);
        return 0;
    }

    // rep(i,1,n+1) {
    //     printf("\n%d::%d\n", len[i], a[i].size());
    //     rep(j,0,a[i].size()) {
    //         printf("%d_", a[i][j].se);
    //     }
    // }
    rep(i,1,n+1) {
        if(a[i].size() >= 2){
            printf("TAK\n");
            rep(j, 1, n + 1){
                if(i == j)
                    printf("%d ", a[j][1].se);
                else
                    printf("%d ", a[j][0].se);
            }
            return 0;
        }
    }

    printf("NIE\n");
    return 0;
}
/*

*/