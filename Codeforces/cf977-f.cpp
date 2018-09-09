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

const int N = 2e5+7;
int T,n,m,k,l,a[N];
map<int, int> dp;
vector<int>ans;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    dp.clear();
    cin >> n;
    int tot = 0;
    rep(i,1,n+1){
        cin >> a[i];
        dp[ a[i] ] = max(dp[ a[i] ], dp[ a[i]-1 ]+1);
        tot = max(tot, dp[ a[i] ]);
    }
    for(auto u:dp){
        if(u.se == tot){
           int cnt = u.fi;
            per(i,1,n+1){
                if(a[i]==cnt){
                    cnt--;
                    ans.pb(i);
                }
            } 
            reverse(all(ans));
            cout << ans.size() << endl;
            for(auto u:ans) cout << u << " ";
            return 0;
        }
    }


    return 0;
}
