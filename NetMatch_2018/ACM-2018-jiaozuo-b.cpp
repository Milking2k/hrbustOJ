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

const int N = 1e3+7;
ll T,n,m,k,a[N];
char s[N];
ll mxdp[N][10];
ll mndp[N][10];
int main()
{
    for(cin >> T;T;T--){
        memset(mxdp,0,sizeof(mxdp));
        memset(mndp,0,sizeof(mndp));

        cin >> n >> m >> k;
        rep(i,1,n+1){
            cin >> a[i];
        }
        cin >> s+1;

        mxdp[0][0] = k;
        mndp[0][0] = k;
        rep(i,1,n+1){
            mxdp[i][0] = k;
            mndp[i][0] = k;

            rep(j,1,m+1){
                ll temp1 = mxdp[i-1][j-1];
                ll temp2 = mndp[i-1][j-1];
                ll mxcnt,mncnt;
                if(s[j]=='+'){
                    mxcnt = max(temp1+a[i], temp2+a[i]);
                    mncnt = min(temp1+a[i], temp2+a[i]);
                }
                else if(s[j]=='-'){
                    mxcnt = max(temp1-a[i], temp2-a[i]);
                    mncnt = min(temp1-a[i], temp2-a[i]);
                }
                else if(s[j]=='*'){
                    mxcnt = max(temp1*a[i], temp2*a[i]);
                    mncnt = min(temp1*a[i], temp2*a[i]);
                }
                else {
                    mxcnt = max(temp1/a[i], temp2/a[i]);
                    mncnt = min(temp1/a[i], temp2/a[i]);
                }
                mxdp[i][j] = max(mxcnt, mxdp[i-1][j]);
                mndp[i][j] = min(mncnt, mndp[i-1][j]);
                if(i==j){
                    mxdp[i][j] = mxcnt;
                    mndp[i][j] = mncnt;
                }
            }
        }
        cout << mxdp[n][m] << endl;
    }

    return 0;
}