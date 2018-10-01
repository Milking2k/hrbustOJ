#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
// const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b, ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;
int T, mod,Cas=0;
ll n, k,x;

struct Matrix
{
    long long mat[2][2];
};
Matrix mul(Matrix a,Matrix b)
{
    Matrix ret;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            ret.mat[i][j]=0;
            for(int k=0;k<2;k++)
            {
                ret.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
                ret.mat[i][j]%=(mod);
            }
        }
    return ret;
}
Matrix pow_M(Matrix a,int n)
{
    Matrix ret;
    memset(ret.mat,0,sizeof(ret.mat));
    ret.mat[0][0]=ret.mat[1][1]=1;
    Matrix temp=a;
    while(n)
    {
        if(n&1)ret=mul(ret,temp);
        temp=mul(temp,temp);
        n>>=1;
    }
    return ret;
}
int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%lld%d", &x, &mod);
        ll Mod = (mod - 1) * (mod + 1);
        ll n = powmod(2, x, Mod)+1;
        int ans[2] = {1, 9};

        printf("Case #%d: ", ++Cas);

        if(n < 2){
            printf("%d\n", ans[n]);
        }
        else{
            Matrix tmp,base;
            base.mat[0][0] = 5;
            base.mat[0][1] = 0;
            base.mat[1][0] = 2;
            base.mat[1][1] = 0;
            tmp.mat[0][0] = 5;
            tmp.mat[0][1] = 12;
            tmp.mat[1][0] = 2;
            tmp.mat[1][1] = 5;
            tmp = pow_M(tmp, n-1);
            base = mul(tmp, base);
            printf("%lld\n", (2 * base.mat[0][0] - 1) % mod);
        }
    }
    return 0;
}
