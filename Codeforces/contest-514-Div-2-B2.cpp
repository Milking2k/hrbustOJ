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
char s[1002][1002];
int vis[1002][1002];
int n,m;
void solve(int x,int y) {
    int ok=1;
    rep(i,1,4) rep(j,1,4) {
        if(i==j && i==2) continue;
        if(s[x+i-1][y+j-1]!='#')ok=0;
    }
    if(ok==1) rep(i,1,4) rep(j,1,4) {
        if(i==j && i==2) continue;
        else if(s[x+i-1][y+j-1]=='#') vis[x+i-1][y+j-1]=1;
    }
}
int main() {
    memset(vis,0,sizeof(vis));
    read(n),read(m);
    rep(i,1,n+1)rep(j,1,m+1) cin>>s[i][j];
    rep(i,1,n+1) {
        rep(j,1,m+1) {
            if(s[i][j]=='#') {
                if(i+2<=n && j+2<=m)solve(i,j);
                if(i+2<=n && j-2>=1)solve(i,j-2);
                if(i-2>=1 && j-2>=1)solve(i-2,j-2);
                if(i-2>=1 && j>=1 && j+2<=m)solve(i-2,j);
                if(i+2<=n && j+1<=m && j-1>=1)solve(i,j-1);
                if(i-1>=1 && j+2<=m && i+1<=n)solve(i-1,j);
                if(i-2>=1 && j-1>=1 && j+1<=m)solve(i-2,j-1);
                if(i-1>=1 && j-2>=1 && i+1<=n)solve(i-1,j-2);
                // if(i-1>=1 && j-2>=1 && i+1<=n)solve(i-1,j-2);
                // if(i-1>=1 && j+2<=m && i+1<=n)solve(i-1,j);
                // if(i+2<=n && j-2>=1)solve(i,j-2);
            }
        }
    }
    int ok=1;
    rep(i,1,n+1) rep(j,1,m+1)if(s[i][j]=='#' && vis[i][j]==0) ok=0;
    if(ok==1)puts("YES");
    else puts("NO");
}

/*
3 8
###.####
#.#.#.##
###.####
*/