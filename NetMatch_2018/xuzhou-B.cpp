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

const int N = 1e3+7;
const int INF = 0x3f3f3f3f;
int T,n,m,k,a[N],b[N],c[N],r,l;
int ans = 0;
int dp[N][207];

int dfs(int i, int now)
{
    if(i==n+1)
        return now;
    if(dp[i][now+100]!=INF)
        return dp[i][now + 100];

    int cnt, tmp;
    if (i & 1){
        tmp = -100;
        if(a[i]){
            cnt = min(100, now + a[i]);
            tmp = max(tmp, dfs(i + 1, cnt));
        }
        if(b[i]){
            cnt = max(-100, now - b[i]);
            tmp = max(tmp, dfs(i + 1, cnt));
        }
        if(c[i]){
            cnt = now * (-1);
            tmp = max(tmp, dfs(i + 1, cnt));
        }
        tmp = min(100, max(-100, tmp));
        dp[i][now + 100] = tmp;
    }
    else{
        tmp = 100;
        if(a[i]){
            cnt = min(100, now + a[i]);
            tmp = min(tmp, dfs(i + 1, cnt));
        }
        if(b[i]){
            cnt = max(-100, now - b[i]);
            tmp = min(tmp, dfs(i + 1, cnt));
        }
        if(c[i]){
            cnt = now * (-1);
            tmp = min(tmp, dfs(i + 1, cnt));
        }
        // tmp = min(100, max(-100, tmp));
        dp[i][now + 100] = tmp;
    }
    return dp[i][now + 100];
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (cin >> n >> m >> r>> l){   
        rep(i,1,n+1){
            cin >> a[i] >> b[i] >> c[i];
        }
        rep(i,0,n+1)rep(j,0,201){
            dp[i][j] = INF;
        }
        ans = dfs(1, m);
        if(ans >= r){
            cout << "Good Ending\n";
        }
        else if(ans <= l)
        {
            cout << "Bad Ending\n";
        }
        else
        {
            cout << "Normal Ending\n";
        }
    }

    return 0;
}