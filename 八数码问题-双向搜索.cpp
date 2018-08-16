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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 362880;
int T,n,m,k,tot,hsmp[2][N],step[2][N],t[2],w[2]={1,1};;
char s[11];
bool flag = false;
int dirx[4]={1,-1,0,0}, diry[4]={0,0,1,-1};
struct data{
    int ary[3][3];
}d[2][N];



bool blow(int x, int y){
    if(x>=3 || y>=3 || x < 0 || y < 0) return 0;
    return 1;
}
int cantor(int x){
    int fac[10]={1,1,2,6,24,120,720,5040,40320,362880},m[9];
    for(int i=9;i>=1;i--){m[i]=x%10;x/=10;}
    int s=0;
    for(int i=1;i<=9;i++)
    {
        int temp=0;
        for(int j=i+1;j<=9;j++)
            if(m[j]<m[i])temp++;
        s+=fac[9-i]*temp;
    }
    return s;
}
int Hash(int a[3][3]){
    int x=0,k=1;
    for(int i=2;i>=0;i--)
       for(int j=2;j>=0;j--)
          {x+=a[i][j]*k;k*=10;}
    return cantor(x);
}

void bfs2way(int k){
    rep(i,0,3)rep(j,0,3){
        d[k][w[k]].ary[i][j] = d[k][t[k]].ary[i][j];
    }
    int x,y;
    rep(i,0,3)rep(j,0,3) if(d[k][t[k]].ary[i][j] == 0){
        x = i, y = j;
        break;
    }

    rep(dir,0,4){
        rep(i,0,3)rep(j,0,3){
            d[k][w[k]].ary[i][j] = d[k][t[k]].ary[i][j];
        }
        int p = x + dirx[dir];
        int q = y + diry[dir];
        if(blow(p,q)){
            swap(d[k][w[k]].ary[x][y], d[k][w[k]].ary[p][q]);
        }

        int temp = Hash(d[k][w[k]].ary);
        if(hsmp[k][temp]==-1){
            step[k][w[k]] = step[k][t[k]] + 1;
            hsmp[k][temp] = step[k][w[k]];
            if(hsmp[0][temp] != -1 && hsmp[1][temp] != -1){
                printf("%d",hsmp[0][temp] + hsmp[1][temp]);
                flag = 1;
                return;
            }
            w[k]++;
        }
    }

    t[k]++;
}

void solve()
{
    while(!flag){
        w[0] - t[0] <= w[1] - t[1] ? bfs2way(0) : bfs2way(1);
    }
}

int main()
{
    char str[15];
    scanf("%s",str);
    int k=0;
    rep(i,0,3)rep(j,0,3){
        d[0][0].ary[i][j] = str[k++] - '0';
    }
    d[1][0] = (data){1,2,3,8,0,4,7,6,5};
    memset(hsmp,-1,sizeof(hsmp));
    hsmp[0][Hash(d[0][0].ary)] = hsmp[1][Hash(d[1][0].ary)] = 0;
    solve();
    return 0;
}

/*

283104765

*/
