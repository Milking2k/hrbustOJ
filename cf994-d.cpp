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
PII a[12],b[12];
set<int> ps;
inline int solve(int i, int j)
{
    if(a[i].fi == b[j].fi || a[i].fi == b[j].se)
        return a[i].fi;
    
    if(a[i].se == b[j].fi || a[i].se == b[j].se)
        return a[i].se;

    return -1;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    ps.clear();

    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i].fi >> a[i].se;
        if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
    }
    rep(i,0,m){
        cin >> b[i].fi >> b[i].se;
        if(b[i].fi > b[i].se) swap(b[i].fi, b[i].se);
    }
    
    rep(i,0,n){
        rep(j,0,m){
            int shd = solve(i,j);
            if(a[i]==b[j] || shd==-1) continue;

            rep(k,0,m){
                if(a[i]!=b[k] && k!=j){
                    int shd2 = solve(i,k);
                    if(shd2 != -1 && shd2 != shd){
                        cout << -1;
                        return 0;
                    }
                }
            }
            rep(k,0,n){
                if(a[k] != b[j] && k!=i){
                    int shd2 = solve(k,j);
                    if(shd2 != -1 && shd2 != shd){
                        cout << -1;
                        return 0;
                    }
                }
            }
            ps.insert(shd);
        }
    }
    if(ps.size()==1) cout << *ps.begin();
    else cout << 0;

    return 0;
}