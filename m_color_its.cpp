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

int n,k,m,x,y,i,ans=0;
int a[1001][1001],f[1001][1001];
 
void dfs(int dep)
{
	int i,j;
	if (dep==n+1){
		ans++;
		return;
	}
    rep(i,1,m+1) if (!f[dep][i]){
            rep(j,1,n+1) if (a[dep][j]){
                f[j][i]++;
            }
            dfs(dep+1);
            rep(j,1,n+1) if (a[dep][j]){
                f[j][i]--;
            }
        }
    return;
} 
 
int main()
{
    int T;
    for(cin >> T; T; T--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        ans = 0;
        scanf("%d%d",&n,&k);
        m = 3;
        rep(i,1,k+1){
            scanf("%d%d",&x,&y);
            x++,y++;
            a[x][y]=1;
            a[y][x]=1;
        }
        dfs(1);
        if(ans==0) cout << "N" << endl;
        else cout << "Y" << endl;
    }
	return 0;
}
