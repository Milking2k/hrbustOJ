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
char a[N][N];
bool vis[N][N];
PII solve(int x, int y){
    int leny = m, lenx = n;
    rep(i,y,m+1){
        if(a[x][i]!='#'){
            leny = i-1;
            break;
        }
    }
    rep(i,x,n+1){
        if(a[i][y]!='#'){
            printf("lenxpo:%d %d %c\n", i, y, a[i][y]);
            lenx = i-1;
            break;
        }
    }
    if(lenx==3 && leny==3 && a[x+1][y+1]=='#')return mp(-1,-1);
    printf("%d %d %d %d \n", x, y,lenx,leny);
    rep(i,x,lenx+1){
        rep(j,y,leny+1){
            printf("lenx:leny:%d %d %c\n", i, j,a[i][j]);
            vis[i][j] = 1;
            if(j==leny && a[i][j]=='.')return mp(-1,-1);
            if(i==lenx && a[i][j]=='.')return mp(-1,-1);
            if((a[i][j]=='.' && a[i][j-1]=='.') || (a[i][j]=='.' && a[i-1][j]=='.')|| (a[i][j]=='.' && a[i-1][j-1]=='.')){
                return mp(-1, -1);
            }
        }
    }
    return mp(lenx, leny);
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin>>n>>m){
        memset(vis, 0, sizeof(vis));
        rep(i,1,n+1){
            scanf("%s", a[i] + 1);
        }
        rep(i,1,n+1){
            rep(j,1,m+1){
                cout << a[i][j];
            }
            cout << endl;
        }
        printf("?:%c\n", a[2][1]);
        PII to;
        bool ok = 0;
        rep(i,1,n+1){
            rep(j,1,m+1){
                to.se = j;
                if(vis[i][j])
                    continue;
                if(a[i][j]=='#'){
                    to = solve(i, j);
                }
                j = to.se;
                printf("nowj:%d\n", j);
                if(to.fi==-1&&to.se==-1){
                    printf("NO\n");
                    ok = 1;
                    break;
                }
            }
            if(ok)
                break;
        }
        if(!ok)printf("YES\n");
    }
    return 0;
}

/*
3 8
###.####
#.#.#.##
###.####
*/