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

const int MAXN = 1e5+7;
const int MAXM = 1e5+7;
int F[N];
struct Edge
{
    int u, v, w;
} edge[N];
int tol;
void addedge(int u, int v, int w)
{
    edge[tol].u = u;
    edge[tol].v = v;
    edge[tol++].w = w;
}

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
int find(int x)
{
    if (F[x] ==-1)
        return x;
    else
        return F[x] = find(F[x]);
}

int Kruskal(int n)
{
    memset(F,-1, sizeof(F));
    sort(edge, edge + tol, cmp);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < tol; i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if (t1 != t2)
        {
            ans += w;
            F[t1] = t2;
            cnt++;
        }
        if (cnt == n-1)
            break;
    }
    if (cnt < n-1)
        return -1; //不连通
    else
        return ans;
}
char ch[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        int k;
        tol = 0;
        scanf("%d", &k);
        scanf("%s", ch);
        scanf("%d%d", &n, &m);
        rep(i,1,m+1){
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u+1, v+1, 1);
            addedge(v+1, u+1, 1);
        }
        int ans = Kruskal(n);
        // printf("%d %d\n", ans, m - ans);
        if (ans == -1 || m - ans - 1 < 0)
        {
            if(ch[0] == '1') printf("2\n");
            else printf("1\n");
            
        }
        else {
            char cur = ch[(m - ans - 1 + 1) % k];
            if(cur == '1') printf("2\n");
            else printf("1\n");
        }
    }
    return 0;
}

/*

*/