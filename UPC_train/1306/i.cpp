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
PII a[N];
// map<int, int> ma;
// PII ma[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) {
        vector<PII> ans;
        memset(a, 0, sizeof(a));
        cin >> n;
        int maxnum = 0;
        int tmp = -1;
        rep(i, 1, 50) a[i].fi = i;
        rep(i,1,n+1){
            int x;
            rep(j,1,7){
                cin >> x;
                a[x].second++;
                a[x].first = x;
                maxnum = max(maxnum, a[x].second);
                if(x==7){
                    tmp = a[x].second;
                }
            }
        }
        sort(a+1, a + 50, [](PII a, PII b) { if(a.se == b.se)return a.fi < b.fi;return a.se > b.se; });
        // rep(i, 1, 50) printf("%d:%d ", a[i].fi,a[i].se);
        int temp = a[0].se;
        bool flag = 0;
        rep(i,1,7){
            if(ans.size()>=6){
                break;
            }
            if(a[i].fi == 7){
                flag = 1;
            }
            ans.pb(a[i]);
        }
        // printf("%d::%d\n", tmp, ans.back().se);
        if(!flag && tmp != -1 && tmp == ans.back().se){
            ans.pop_back();
            ans.pb(mp(7, tmp));
        }
        sort(ans.begin(), ans.end());
        rep(i,0,6){
            printf("%d", ans[i].fi);
            if(i!=5){
                printf(" ");
            }
            else{
                printf("\n");
            }
        }
        

    }
    return 0;
}
/*

*/