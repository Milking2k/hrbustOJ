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
const int N = 1e5+7;
int T,n,m;
int a[N];
PII b[N];
map<int, int> lencount;
// map<int, vector<int> > numcount;
unordered_map<int, int> lastpose;
vector<int> v[N];

int c[N];
int lowbit(int x)
{
    return x&(-x);
}
void Add(int pos,int val)
{
    for(int i=pos;i<=n;i+=lowbit(i))
        c[i]+=val;
}
int Sum(int pos)
{
    int ret=0;
    for(int i=pos;i>0;i-=lowbit(i))
        ret+=c[i];
    return ret;
}


int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        int totnum = 0;
        // numcount.clear();
        lastpose.clear();
        memset(c, 0, sizeof(c));

        scanf("%d", &n);
        rep(i, 1, n + 1){
            scanf("%d", a + i);
            b[i].fi = a[i];
            b[i].se = i;
            // numcount[a[i]].pb(i);
        }
        sort(b + 1, b + 1 + n);
        rep(i, 2, n + 1) {
            if(b[i].fi == b[i - 1].fi) {
                v[b[i].se].pb(b[i - 1].se);
            }
        }

        // for (auto num:numcount) {
        //     if(num.se.size() <= 1) continue;
        //     int len = num.se.size();
        //     rep(i,1,len) {
        //         v[num.se[i]].pb(num.se[i - 1]);
        //     }
        // }
        for (int i = 1; i <= n; i++)
        {
            if (lastpose.find(a[i]) != lastpose.end())
                Add(lastpose[a[i]], -1);
            Add(i, 1);
            lastpose[a[i]] = i;
            for (int j = 0; j < v[i].size(); j++)
            {
                int L = v[i][j];
                int R = i;
                int sum = Sum(R) - Sum(L - 1);
                lencount[sum]++;
            }
            v[i].clear();
        }

        int cur = n;
        rep(i, 1, n + 1) {
            cur -= lencount[i];
            lencount[i] = 0;
            i == n ? printf("%d\n", cur) : printf("%d ", cur);
        }

    }
    return 0;
}
/*

*/