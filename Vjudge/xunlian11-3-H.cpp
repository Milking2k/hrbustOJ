#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
const int N = 1e2+7;
int T,n,m;
VI X,Y,H;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i,0,n){
        int x, y, h;
        cin >> x >> y >> h;
        X.pb(x),Y.pb(y),H.pb(h);
    }
    rep(x,0,101){
        rep(y,0,101){
            int height = -1;
            bool flag = 0;
            rep(i,0,n){
                if(H[i]==0)
                    continue;
                if(height==-1)
                    height = H[i] + abs(X[i] - x) + abs(Y[i] - y);
                else if(height != H[i] + abs(X[i] - x) + abs(Y[i] - y))
                    flag = 1;
            }
            rep(i,0,n){
                if(H[i]==0 && (height-abs(X[i]-x)-abs(Y[i]-y) > 0))
                    flag = 1;
            }
            if(!flag){
				cout<<x<<" "<<y<<" "<<height<<endl;
                return 0;
            }
        }
    }
    return 0;
}