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
const int N = 1e3+7;
int T,n,m;
int a[N][N], row[N], col[N];
bool vis1[N], vis2[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;

    int globalMin = 600;
    rep(i,1,n+1) {
        int minum = 600;
        rep(j,1,m+1) {
            cin >> a[i][j];
            minum = min(minum, a[i][j]);
            globalMin = min(globalMin, a[i][j]);
        }
        row[i] = minum;
    }
    rep(j,1,m+1) {
        int minum = 600;
        rep(i,1,n+1) {
            minum = min(minum, a[i][j]);
        }
        col[j] = minum;
    }

    bool ok = 0;
    int ans = 0;
    rep(i,1,n+1) { // row
        rep(j,1,m+1) {
            int rownum = row[i] - globalMin;
            int colnum = col[j] - globalMin;
            if(rownum + colnum != a[i][j] - globalMin){
                ok = 1;
            }
        }
    }
    if(ok){
        printf("-1\n");
        return 0;
    }

    rep(i,1,n+1){
        ans += max(0, row[i] - globalMin);
    }
    rep(i,1,m+1){
        ans += max(0, col[i] - globalMin);
    }

    ans += globalMin*min(n,m);
    printf("%d\n", ans);

    rep(i,1,min(n,m)+1){
        rep(j,1,globalMin+1){
            if(n < m)
                printf("row %d\n", i);
            else
                printf("col %d\n", i);
        }
    }

    rep(i,1,n+1){
        rep(k,1,row[i] + 1 - globalMin){
            printf("row %d\n", i);
        }
    }
    
    rep(i,1,m+1){
        rep(k,1,col[i] + 1 - globalMin){
            printf("col %d\n", i);
        }
    }
    
    

    return 0;
}
/*
*/