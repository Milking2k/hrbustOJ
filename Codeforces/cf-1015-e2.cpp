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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e3+7;
struct node {
    int x,y,val;
}ans[2000007];

struct dirlen{
    int fi,se;
}prelen[N][N], lstlen[N][N];

int n,m,k,tot=0;
char s[1007][1007];
int dir[5][5]={ {1,0},{-1,0},{0,1},{0,-1} };
bool vis[1007][1007];
//int prelen[N][N];
//int lstlen[N][N];

int minlen = 0x3f3f3f3f;
inline bool check(int i, int j) {
    return (1<=i && i<=n && 1<=j && j<=m);
}

void dfs(int x, int y, int len){
    printf("now:x,y,len: %d %d %d\n",x,y,len);
    vis[x][y] = true;

    rep(i,0,4){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        rep(j,1,len+1){
            if((i==1||i==3) && vis[nx][ny]==true) break;// left and up had been marked
            vis[nx][ny] = true;
            nx += dir[i][0];
            ny += dir[i][1];
        }
    }
    ans[tot].x = x;
    ans[tot].y = y;
    ans[tot].val = len;
    tot++;
}


int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    rep(i,1,n+1){
        rep(j,1,m+1){
            scanf("%c", &s[i][j]);
            vis[i][j] = false;// init vis;
        }
        getchar();
    }

    if(s[1][1]=='*' || s[n][1]=='*' || s[1][m]=='*' || s[n][m]=='*')
        return !printf("-1");

    // slove pre and lst to get min len of four dir
    // 1e6
    rep(i,1,n+1)
    rep(j,1,m+1){
        if(s[i][j] == '*'){
            prelen[i][j].fi = 1 + prelen[i][j-1].fi;
            prelen[i][j].se = 1 + prelen[i-1][j].se;
        }
        if(s[n-i+1][m-j+1] == '*'){
            lstlen[n-i+1][m-j+1].fi = 1 + lstlen[n-i+1][m-j].fi);
            lstlen[n-i+1][m-j+1].se = 1 + lstlen[n-i][m-j+1].se);
        }
    }

    //debug
    rep(i,1,n+1)
    rep(j,1,m+1){
        printf(j==m?"%d\n":"%d ",prelen[i][j]);
    }

    rep(i,1,n+1)
    rep(j,1,m+1){
        printf(j==m?"%d\n":"%d ",lstlen[i][j]);
    }

    // dfs to mark
    rep(i,1,n+1)
    rep(j,1,m+1){
        minlen = min(prelen[i][j], lstlen[i][j]);
        if(s[i][j]=='*' && minlen >= 1) dfs(i,j,minlen);
    }

    // 1e6
    rep(i,1,n+1)
    rep(j,1,m+1){
        if(s[i][j]=='*' && !vis[i][j])
            return !printf("-1");
    }

    printf("%d\n",tot);
    rep(i,0,tot){
        printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].val);
    }


    return 0;
}


