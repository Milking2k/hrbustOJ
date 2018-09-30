#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
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

const int N = 2e6+7;
ll n, m, k;
int T,Cas=0;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (cin >> T; T;T--){
        cin >> n >> m >> k;
        vector<int> b;
        int pos = 1, mx = 0x3f3f3f3f;
        rep(i, 1, n+1) cin >> a[i];
        sort(a + 1, a + 1 + n);
        rep(i, 1, n + 1){
            if (abs(mx) > abs(a[i])){
                pos = i;
                mx = a[i];
            }
            else if(abs(mx) == abs(a[i])){
                if(i<n-1){
                    pos = i;
                    mx = a[i];
                }
            }
        }
        b.pb(a[1]);
        b.pb(a[2]);
        if(pos!=1 && pos!=2) b.pb(a[pos]);
        if(pos!=n && n!=2 && n!=1) b.pb(a[n]);
        if(pos!=n-1 && (n-1)!=2 && (n-1)!=1) b.pb(a[n-1]);

        ll ans = -1*0x3f3f3f3f3f3f3f3f;
        int len = b.size();
        // for(auto u:b){
        //     printf("%d ", u);
        // }
        // puts("");
        rep(i,0,len){
            rep(j,0,len){
                if(i==j) continue;
                ans = max(ans, m * b[i] * b[i] + k * b[j]);
            }
        }
        cout << "Case #" << ++Cas << ": ";
        cout << ans << "\n";
    }
        return 0;
}

/*
1
2 1 2
-1 1
*/