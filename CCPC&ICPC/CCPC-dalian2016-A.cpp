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

const int N = 1e5 + 5;
int a[N], b[N], vis[N];
int main()
{
    int n, m, x, y, k;
    while (scanf("%d%d%d%d", &n, &m, &x, &y) != EOF)
    {
        memset(vis, -1, sizeof(vis));
        for (int i = 1; i <= m; i++)
            scanf("%d%d", &a[i], &b[i]);
        for (int i = 1; i <= x; i++)
        {
            scanf("%d", &k);
            vis[k] = 1;
        }
        for (int i = 1; i <= y; i++)
        {
            scanf("%d", &k);
            vis[k] = 0;
        }
        int flag = 0;
        for (int i = 1; i <= m; i++)
        {
            if (vis[a[i]] == -1 && vis[b[i]] == -1)
                vis[a[i]] = 1, vis[b[i]] = 0;
            else if (vis[a[i]] != -1 && vis[b[i]] == -1)
                vis[b[i]] = vis[a[i]] ^ 1;
            else if (vis[a[i]] == -1 && vis[b[i]] != -1)
                vis[a[i]] = vis[b[i]] ^ 1;
            else if (vis[a[i]] == vis[b[i]] && vis[a[i]] != -1) 
                flag = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == -1)
                flag = 1;
        }
        if (flag == 1)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}
