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

struct node {
    int x,y,val;
}ans[2000007];
int n,m,k,tot=0;
char s[1007][1007];
int dir[5][5]={ {1,0},{-1,0},{0,1},{0,-1} };
bool vis[1007][1007];

inline bool check(int i, int j) {
    return (1<=i && i<=n && 1<=j && j<=m);
}

void dfs(int x, int y){
//    printf("now:x,y: %d %d\n",x,y);
    int minlen = 0x3f3f3f3f;
    int cntmaxlen;

    rep(i,0,4){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        cntmaxlen = 0;
        while(check(nx,ny) && s[nx][ny]=='*'){
            nx += dir[i][0];
            ny += dir[i][1];
            cntmaxlen++;
            if(cntmaxlen > minlen) break;
        }
        minlen = min(minlen, cntmaxlen);
    }

//    printf("now:x,y: %d %d\n",x,y);
    if(minlen > 0){
//        printf("enable %d\n",minlen);
        // check vis
        rep(i,0,4){
            vis[x][y] = true;

            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            rep(j,1,minlen+1){
                vis[nx][ny] = true;
                nx += dir[i][0];
                ny += dir[i][1];
            }
        }
        // add to ans
        ans[tot].x = x;
        ans[tot].y = y;
        ans[tot].val = minlen;
        tot++;
    }
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

    // bug

//    printf("%c",s[1][1]);
//    rep(i,1,n+1){
//        rep(j,1,m+1){
//            printf("%c",s[i][j]);
//        }
//        puts("");
//    }

    if(s[1][1]=='*' || s[n][1]=='*' || s[1][m]=='*' || s[n][m]=='*')
        return !printf("-1");


    rep(i,1,n+1)
    rep(j,1,m+1){
        if(s[i][j]=='*') dfs(i,j);
    }

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

