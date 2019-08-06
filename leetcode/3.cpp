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
int T,n,m;
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int vis[300];
    memset(vis, -1, sizeof(vis));
    int mxlen = 0;
    int retmx = 0;
    int curminpos = -1;
    for (int i = 0; i < s.length(); ++i) {
        if(vis[s[i]] == -1) {
            vis[s[i]] = i;
            mxlen++;
        }
        else {
            if(vis[s[i]] < curminpos) {
                vis[s[i]] = i;
                mxlen++;
            }
            else {
                retmx = max(retmx, mxlen);
                mxlen = i - vis[s[i]];
                curminpos = vis[s[i]];
                vis[s[i]] = i;
            }
        }
    }
    retmx = max(retmx, mxlen);
    printf("%d\n", retmx);
    return 0;
}
/*
dvdf
tmmzuxt

 */