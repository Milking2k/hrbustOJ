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

const int N = 1e+7;
int T,n,m,k,ans;
int c[20][20];
bitset<1000> row,cal,block[10][10];

void dfs()
{


}

int main()
{
    for(scanf("%d",&T);T;T--){
        getchar();
        rep(i,1,10){
            rep(j,1,10) {
                scanf("%c",&c[i][j]);
                if(c[i][j]!='0') row.set(c[i][j]-'0');
            }getchar();
        }
//        rep(i,1,10) rep(j,1,10) printf(j==9?"%d\n":"%d ",c[i][j]-'0');

        rep(i,1,10) rep(j,1,10){
            if(c[j][i] != '0') col.set(c[j][i] - '0');
        }
        rep(i,1,10) rep(j,1,10){
            if(c[i][j] != '0') block[ (i-1)/3 ][ (j-1)/3 ].set(c[i][j] - '0');
        }

        dfs();
    }
    return 0;
}

